/*
Copyright (C) 2024 Ian Sloat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#pragma once

#include <opencv2/opencv.hpp>

namespace me {
	
	namespace dnn {

		// GENERAL TODO: Make generic class definitions for model types <- DONE

		enum class Precision { // Status flag for model classes
			FLOAT64,
			FLOAT32,
			FLOAT16,
			INT64,
			INT32,
			INT16,
			INT8,
			UNKNOWN,
			NONE
		};

		enum class Executor { // Status flag for model classes
			TENSORRT,
			CUDA,
			CPU,
			NONE
		};

		enum class BlobLayout {
			NCHW,
			NHWC,
			CHWN
		};

		enum class CropMethod {
			FIT,
			LETTERBOX,
			NONE
		};

		enum class SetIdentityType {
			MEAN,
			MEDIAN,
			LAST
		};

		struct Detection {
			Detection();
			Detection(int class_id, cv::Rect2d bbox, float score);
			int class_id;
			cv::Rect2d bbox;
			float score;
		};

		struct Joint {
			Joint();
			Joint(cv::Point2d pt, double prob);
			Joint(double x, double y, double prob);
			double prob;
			cv::Point2d pt;
		};

		struct Pose {
			Pose();
			void set_joint(int id, Joint& joint);
			void set_joint(int id, cv::Point2d& pt, double prob);
			void set_joint(int id, double x, double y, double prob);
			Joint& get_joint(int id);
			bool has_joint(int id);
			std::set<int> get_joint_ids();
			int num_joints();
			Joint& operator[](int id);
			std::map<int, Joint> joints;
		};

		struct Feature {
			Feature() {}
			Feature(std::vector<double>& data) : data(data) {}
			Feature(std::initializer_list<double> data) : data(data) {}
			Feature(const Feature& other) : data(other.data) {}
			std::vector<double> data;
			double norm() const;
			Feature operator/(double val) const;
			Feature operator-(Feature& other) const;
			Feature& operator=(const Feature& other);
			double similarity(const Feature& other) const;
			size_t size() const;
		};

		/// <summary>
		/// Specialized container for fast mean and median operations on a managed set of feature vectors.
		/// 
		/// Currently uses a list of sets for each element so that everything is pre-sorted for median calculations.
		/// This currently uses a linear search which could slow down operations when the feature length reaches a considerable size
		/// Consider using a custon implementation of a red-black tree that uses order statistics for faster search and insert
		/// </summary>
		class FeatureSet {
		public:
			FeatureSet(size_t feature_length);
			void add(Feature& f);
			Feature& at(size_t index);
			void remove(size_t index);
			void erase(std::vector<Feature>::iterator position);
			Feature mean();
			Feature median();
			std::vector<Feature>::iterator begin();
			std::vector<Feature>::iterator end();
			size_t size();
			size_t length();
			Feature& operator[](size_t index);
		private:
			std::vector<Feature> features;
			size_t feature_length;
			struct ptr_cmp {
				bool operator()(double* a, double* b) const {
					return *a < *b;
				}
			};
			std::vector<std::multiset<double*, ptr_cmp>> feature_elements;
		};

		class FeatureSpace {
		public:
			FeatureSpace(size_t feature_length) : feature_length(feature_length) {}
			std::vector<FeatureSet>::iterator assign(Feature &input, double threshold = 0.8, SetIdentityType identity_type = SetIdentityType::MEDIAN);
			std::vector<std::vector<FeatureSet>::iterator> assign(std::vector<Feature>& input, double threshold = 0.8, SetIdentityType identity_type = SetIdentityType::MEDIAN,
				std::vector<std::vector<FeatureSet>::iterator> mask = std::vector<std::vector<FeatureSet>::iterator>());
			std::vector<FeatureSet>::iterator begin();
			std::vector<FeatureSet>::iterator end();
			size_t size();
			size_t length();
		private:
			size_t feature_length;
			std::vector<FeatureSet> feature_sets;
		};

		inline double iou(cv::Rect2d a, cv::Rect2d b);

		std::vector<size_t> nms(std::vector<Detection>& detections, float iou_thresh);

		cv::Mat resize_to_net(const cv::Mat& img, cv::Size new_size);

		void blobifyImages(const std::vector<cv::Mat>& images,
			std::vector<float>& output,
			double scale = 1.0,
			const cv::Scalar& mean = cv::Scalar(),
			const cv::Scalar& std_dev = cv::Scalar(),
			const cv::Size& out_size = cv::Size(),
			bool swapRB = false,
			bool use_cuda = false,
			CropMethod crop_method = CropMethod::NONE,
			BlobLayout layout = BlobLayout::NCHW);

		std::vector<float> LetterboxImage(const cv::Mat& src, cv::Mat& dst, const cv::Size& out_size, bool use_cuda = true);

		std::vector<float> FitImage(const cv::Mat& src, cv::Mat& dst, const cv::Size& out_size, bool use_cuda = true);

		void StretchImage(const cv::Mat& src, cv::Mat& dst, const cv::Size& out_size, bool use_cuda = true);

		bool checkForProvider(const std::string provider_str);

		cv::Mat getRoiWithPadding(const cv::Mat& image, cv::Rect roi);

	}

}