/*
*
*/

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>


#ifdef MECORE_EXPORTS

#define MECORE __declspec(dllexport)

#else

#define MECORE __declspec(dllimport)

#endif

#ifndef ME_CCTAG_HPP
#define ME_CCTAG_HPP

namespace me {
	namespace cc {

		enum PREDEFINED_DICTIONARY_NAME {
			DICT_CCTAG_3CROWNS,
			DICT_CCTAG_4CROWNS
		};

		enum DETECTION_STATUS {
			CCTAG_UNRELIABLE,
			CCTAG_RELIABLE
		};

		const std::string cctag_dictionary_names[2] = { "DICT_CCTAG_3CROWNS", "DICT_CCTAG_4CROWNS" };

		const int cctag_3crown_scales[32][5] = {
			{90, 80, 70, 60, 50},
			{90, 80, 70, 60, 45},
			{90, 80, 70, 55, 45},
			{90, 80, 70, 55, 40},
			{90, 80, 65, 55, 45},
			{90, 80, 65, 55, 40},
			{90, 80, 65, 50, 40},
			{90, 80, 65, 50, 35},
			{90, 75, 65, 55, 45},
			{90, 75, 65, 55, 40},
			{90, 75, 65, 50, 40},
			{90, 75, 65, 50, 35},
			{90, 75, 60, 50, 40},
			{90, 75, 60, 50, 35},
			{90, 75, 60, 45, 35},
			{90, 75, 60, 45, 30},
			{85, 75, 65, 55, 45},
			{85, 75, 65, 55, 40},
			{85, 75, 65, 50, 40},
			{85, 75, 65, 50, 35},
			{85, 75, 60, 50, 40},
			{85, 75, 60, 50, 35},
			{85, 75, 60, 45, 35},
			{85, 75, 60, 45, 30},
			{85, 70, 60, 50, 40},
			{85, 70, 60, 50, 35},
			{85, 70, 60, 45, 35},
			{85, 70, 60, 45, 30},
			{85, 70, 55, 45, 35},
			{85, 70, 55, 45, 30},
			{85, 70, 55, 40, 30},
			{85, 70, 55, 40, 25}
		};

		const int cctag_4crown_scales[128][7] = {
			{92, 84, 76, 68, 60, 52, 44},
			{92, 84, 76, 68, 60, 52, 40},
			{92, 84, 76, 68, 60, 48, 40},
			{92, 84, 76, 68, 60, 48, 36},
			{92, 84, 76, 68, 56, 48, 40},
			{92, 84, 76, 68, 56, 48, 36},
			{92, 84, 76, 68, 56, 44, 36},
			{92, 84, 76, 68, 56, 44, 32},
			{92, 84, 76, 64, 56, 48, 40},
			{92, 84, 76, 64, 56, 48, 36},
			{92, 84, 76, 64, 56, 44, 36},
			{92, 84, 76, 64, 56, 44, 32},
			{92, 84, 76, 64, 52, 44, 36},
			{92, 84, 76, 64, 52, 44, 32},
			{92, 84, 76, 64, 52, 40, 32},
			{92, 84, 76, 64, 52, 40, 28},
			{92, 84, 72, 64, 56, 48, 40},
			{92, 84, 72, 64, 56, 48, 36},
			{92, 84, 72, 64, 56, 44, 36},
			{92, 84, 72, 64, 56, 44, 32},
			{92, 84, 72, 64, 52, 44, 36},
			{92, 84, 72, 64, 52, 44, 32},
			{92, 84, 72, 64, 52, 40, 32},
			{92, 84, 72, 64, 52, 40, 28},
			{92, 84, 72, 60, 52, 44, 36},
			{92, 84, 72, 60, 52, 44, 32},
			{92, 84, 72, 60, 52, 40, 32},
			{92, 84, 72, 60, 52, 40, 28},
			{92, 84, 72, 60, 48, 40, 32},
			{92, 84, 72, 60, 48, 40, 28},
			{92, 84, 72, 60, 48, 36, 28},
			{92, 84, 72, 60, 48, 36, 24},
			{92, 80, 72, 64, 56, 48, 40},
			{92, 80, 72, 64, 56, 48, 36},
			{92, 80, 72, 64, 56, 44, 36},
			{92, 80, 72, 64, 56, 44, 32},
			{92, 80, 72, 64, 52, 44, 36},
			{92, 80, 72, 64, 52, 44, 32},
			{92, 80, 72, 64, 52, 40, 32},
			{92, 80, 72, 64, 52, 40, 28},
			{92, 80, 72, 60, 52, 44, 36},
			{92, 80, 72, 60, 52, 44, 32},
			{92, 80, 72, 60, 52, 40, 32},
			{92, 80, 72, 60, 52, 40, 28},
			{92, 80, 72, 60, 48, 40, 32},
			{92, 80, 72, 60, 48, 40, 28},
			{92, 80, 72, 60, 48, 36, 28},
			{92, 80, 72, 60, 48, 36, 24},
			{92, 80, 68, 60, 52, 44, 36},
			{92, 80, 68, 60, 52, 44, 32},
			{92, 80, 68, 60, 52, 40, 32},
			{92, 80, 68, 60, 52, 40, 28},
			{92, 80, 68, 60, 48, 40, 32},
			{92, 80, 68, 60, 48, 40, 28},
			{92, 80, 68, 60, 48, 36, 28},
			{92, 80, 68, 60, 48, 36, 24},
			{92, 80, 68, 56, 48, 40, 32},
			{92, 80, 68, 56, 48, 40, 28},
			{92, 80, 68, 56, 48, 36, 28},
			{92, 80, 68, 56, 48, 36, 24},
			{92, 80, 68, 56, 44, 36, 28},
			{92, 80, 68, 56, 44, 36, 24},
			{92, 80, 68, 56, 44, 32, 24},
			{92, 80, 68, 56, 44, 32, 20},
			{88, 80, 72, 64, 56, 48, 40},
			{88, 80, 72, 64, 56, 48, 36},
			{88, 80, 72, 64, 56, 44, 36},
			{88, 80, 72, 64, 56, 44, 32},
			{88, 80, 72, 64, 52, 44, 36},
			{88, 80, 72, 64, 52, 44, 32},
			{88, 80, 72, 64, 52, 40, 32},
			{88, 80, 72, 64, 52, 40, 28},
			{88, 80, 72, 60, 52, 44, 36},
			{88, 80, 72, 60, 52, 44, 32},
			{88, 80, 72, 60, 52, 40, 32},
			{88, 80, 72, 60, 52, 40, 28},
			{88, 80, 72, 60, 48, 40, 32},
			{88, 80, 72, 60, 48, 40, 28},
			{88, 80, 72, 60, 48, 36, 28},
			{88, 80, 72, 60, 48, 36, 24},
			{88, 80, 68, 60, 52, 44, 36},
			{88, 80, 68, 60, 52, 44, 32},
			{88, 80, 68, 60, 52, 40, 32},
			{88, 80, 68, 60, 52, 40, 28},
			{88, 80, 68, 60, 48, 40, 32},
			{88, 80, 68, 60, 48, 40, 28},
			{88, 80, 68, 60, 48, 36, 28},
			{88, 80, 68, 60, 48, 36, 24},
			{88, 80, 68, 56, 48, 40, 32},
			{88, 80, 68, 56, 48, 40, 28},
			{88, 80, 68, 56, 48, 36, 28},
			{88, 80, 68, 56, 48, 36, 24},
			{88, 80, 68, 56, 44, 36, 28},
			{88, 80, 68, 56, 44, 36, 24},
			{88, 80, 68, 56, 44, 32, 24},
			{88, 80, 68, 56, 44, 32, 20},
			{88, 76, 68, 60, 52, 44, 36},
			{88, 76, 68, 60, 52, 44, 32},
			{88, 76, 68, 60, 52, 40, 32},
			{88, 76, 68, 60, 52, 40, 28},
			{88, 76, 68, 60, 48, 40, 32},
			{88, 76, 68, 60, 48, 40, 28},
			{88, 76, 68, 60, 48, 36, 28},
			{88, 76, 68, 60, 48, 36, 24},
			{88, 76, 68, 56, 48, 40, 32},
			{88, 76, 68, 56, 48, 40, 28},
			{88, 76, 68, 56, 48, 36, 28},
			{88, 76, 68, 56, 48, 36, 24},
			{88, 76, 68, 56, 44, 36, 28},
			{88, 76, 68, 56, 44, 36, 24},
			{88, 76, 68, 56, 44, 32, 24},
			{88, 76, 68, 56, 44, 32, 20},
			{88, 76, 64, 56, 48, 40, 32},
			{88, 76, 64, 56, 48, 40, 28},
			{88, 76, 64, 56, 48, 36, 28},
			{88, 76, 64, 56, 48, 36, 24},
			{88, 76, 64, 56, 44, 36, 28},
			{88, 76, 64, 56, 44, 36, 24},
			{88, 76, 64, 56, 44, 32, 24},
			{88, 76, 64, 56, 44, 32, 20},
			{88, 76, 64, 52, 44, 36, 28},
			{88, 76, 64, 52, 44, 36, 24},
			{88, 76, 64, 52, 44, 32, 24},
			{88, 76, 64, 52, 44, 32, 20},
			{88, 76, 64, 52, 40, 32, 24},
			{88, 76, 64, 52, 40, 32, 20},
			{88, 76, 64, 52, 40, 28, 20},
			{88, 76, 64, 52, 40, 28, 16}
		};

		class MECORE CCTagMarker {
		public:
			CCTagMarker(int id, cv::Point2f center, DETECTION_STATUS status, cv::Size2f ellipse_size, double angle);
			const cv::Point2f center;
			const int status;
			const cv::Size2f ellipse_size;
			const double angle;
			const int id;
		};

		class MECORE CCTagDetector {
		public:
			CCTagDetector(int dictionary = DICT_CCTAG_3CROWNS, bool use_cuda = true);
			std::vector<CCTagMarker> detect(cv::Mat &input, int frame_id = 0, int pipe_id = 0);
		private:
			const int dictionary;
			const bool use_cuda;
		};

		MECORE void drawMarkers(cv::Mat& input, std::vector<CCTagMarker>& markers);

	}
}

extern "C" MECORE void cctag_analyse_image(char* in_file, char* out_file);

#endif
