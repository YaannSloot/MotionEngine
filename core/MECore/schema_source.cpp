#include <pch.h>
#include <schema_asset.h>

unsigned char calibration_config_bson[4088] = {
  0xf8, 0x0f, 0x00, 0x00, 0x02, 0x74, 0x69, 0x74, 0x6c, 0x65, 0x00, 0x13,
  0x00, 0x00, 0x00, 0x63, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0x74, 0x69,
  0x6f, 0x6e, 0x5f, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x00, 0x02, 0x64,
  0x65, 0x73, 0x63, 0x72, 0x69, 0x70, 0x74, 0x69, 0x6f, 0x6e, 0x00, 0x04,
  0x00, 0x00, 0x00, 0x31, 0x2e, 0x30, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65,
  0x00, 0x07, 0x00, 0x00, 0x00, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x00,
  0x03, 0x70, 0x72, 0x6f, 0x70, 0x65, 0x72, 0x74, 0x69, 0x65, 0x73, 0x00,
  0x94, 0x0d, 0x00, 0x00, 0x03, 0x64, 0x6f, 0x77, 0x6e, 0x73, 0x61, 0x6d,
  0x70, 0x6c, 0x65, 0x5f, 0x68, 0x65, 0x69, 0x67, 0x68, 0x74, 0x00, 0x28,
  0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x08, 0x00, 0x00,
  0x00, 0x69, 0x6e, 0x74, 0x65, 0x67, 0x65, 0x72, 0x00, 0x01, 0x6d, 0x69,
  0x6e, 0x69, 0x6d, 0x75, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xf0, 0x3f, 0x00, 0x03, 0x63, 0x6c, 0x65, 0x61, 0x72, 0x5f, 0x70, 0x6f,
  0x69, 0x6e, 0x74, 0x5f, 0x63, 0x61, 0x63, 0x68, 0x65, 0x00, 0x17, 0x00,
  0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x62, 0x6f, 0x6f, 0x6c, 0x65, 0x61, 0x6e, 0x00, 0x00, 0x03, 0x73, 0x79,
  0x6e, 0x63, 0x5f, 0x70, 0x72, 0x6f, 0x70, 0x65, 0x72, 0x74, 0x69, 0x65,
  0x73, 0x00, 0x86, 0x02, 0x00, 0x00, 0x04, 0x72, 0x65, 0x71, 0x75, 0x69,
  0x72, 0x65, 0x64, 0x00, 0x2f, 0x00, 0x00, 0x00, 0x02, 0x30, 0x00, 0x12,
  0x00, 0x00, 0x00, 0x6d, 0x61, 0x72, 0x6b, 0x65, 0x72, 0x5f, 0x64, 0x69,
  0x63, 0x74, 0x69, 0x6f, 0x6e, 0x61, 0x72, 0x79, 0x00, 0x02, 0x31, 0x00,
  0x0a, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x72, 0x6b, 0x65, 0x72, 0x5f, 0x69,
  0x64, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x07, 0x00, 0x00,
  0x00, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x00, 0x03, 0x70, 0x72, 0x6f,
  0x70, 0x65, 0x72, 0x74, 0x69, 0x65, 0x73, 0x00, 0x2b, 0x02, 0x00, 0x00,
  0x03, 0x6d, 0x61, 0x72, 0x6b, 0x65, 0x72, 0x5f, 0x64, 0x69, 0x63, 0x74,
  0x69, 0x6f, 0x6e, 0x61, 0x72, 0x79, 0x00, 0xf1, 0x01, 0x00, 0x00, 0x02,
  0x74, 0x79, 0x70, 0x65, 0x00, 0x07, 0x00, 0x00, 0x00, 0x73, 0x74, 0x72,
  0x69, 0x6e, 0x67, 0x00, 0x04, 0x65, 0x6e, 0x75, 0x6d, 0x00, 0xd5, 0x01,
  0x00, 0x00, 0x02, 0x30, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43,
  0x54, 0x5f, 0x34, 0x58, 0x34, 0x5f, 0x35, 0x30, 0x00, 0x02, 0x31, 0x00,
  0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x34, 0x58, 0x34,
  0x5f, 0x31, 0x30, 0x30, 0x00, 0x02, 0x32, 0x00, 0x0d, 0x00, 0x00, 0x00,
  0x44, 0x49, 0x43, 0x54, 0x5f, 0x34, 0x58, 0x34, 0x5f, 0x32, 0x35, 0x30,
  0x00, 0x02, 0x33, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54,
  0x5f, 0x34, 0x58, 0x34, 0x5f, 0x31, 0x30, 0x30, 0x30, 0x00, 0x02, 0x34,
  0x00, 0x0c, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x35, 0x58,
  0x35, 0x5f, 0x35, 0x30, 0x00, 0x02, 0x35, 0x00, 0x0d, 0x00, 0x00, 0x00,
  0x44, 0x49, 0x43, 0x54, 0x5f, 0x35, 0x58, 0x35, 0x5f, 0x31, 0x30, 0x30,
  0x00, 0x02, 0x36, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54,
  0x5f, 0x35, 0x58, 0x35, 0x5f, 0x32, 0x35, 0x30, 0x00, 0x02, 0x37, 0x00,
  0x0e, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x35, 0x58, 0x35,
  0x5f, 0x31, 0x30, 0x30, 0x30, 0x00, 0x02, 0x38, 0x00, 0x0c, 0x00, 0x00,
  0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x36, 0x58, 0x36, 0x5f, 0x35, 0x30,
  0x00, 0x02, 0x39, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54,
  0x5f, 0x36, 0x58, 0x36, 0x5f, 0x31, 0x30, 0x30, 0x00, 0x02, 0x31, 0x30,
  0x00, 0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x36, 0x58,
  0x36, 0x5f, 0x32, 0x35, 0x30, 0x00, 0x02, 0x31, 0x31, 0x00, 0x0e, 0x00,
  0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x36, 0x58, 0x36, 0x5f, 0x31,
  0x30, 0x30, 0x30, 0x00, 0x02, 0x31, 0x32, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x44, 0x49, 0x43, 0x54, 0x5f, 0x37, 0x58, 0x37, 0x5f, 0x35, 0x30, 0x00,
  0x02, 0x31, 0x33, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54,
  0x5f, 0x37, 0x58, 0x37, 0x5f, 0x31, 0x30, 0x30, 0x00, 0x02, 0x31, 0x34,
  0x00, 0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x37, 0x58,
  0x37, 0x5f, 0x32, 0x35, 0x30, 0x00, 0x02, 0x31, 0x35, 0x00, 0x0e, 0x00,
  0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x37, 0x58, 0x37, 0x5f, 0x31,
  0x30, 0x30, 0x30, 0x00, 0x02, 0x31, 0x36, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x44, 0x49, 0x43, 0x54, 0x5f, 0x41, 0x52, 0x55, 0x43, 0x4f, 0x5f, 0x4f,
  0x52, 0x49, 0x47, 0x49, 0x4e, 0x41, 0x4c, 0x00, 0x02, 0x31, 0x37, 0x00,
  0x13, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x41, 0x50, 0x52,
  0x49, 0x4c, 0x54, 0x41, 0x47, 0x5f, 0x31, 0x36, 0x68, 0x35, 0x00, 0x02,
  0x31, 0x38, 0x00, 0x13, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f,
  0x41, 0x50, 0x52, 0x49, 0x4c, 0x54, 0x41, 0x47, 0x5f, 0x32, 0x35, 0x68,
  0x39, 0x00, 0x02, 0x31, 0x39, 0x00, 0x14, 0x00, 0x00, 0x00, 0x44, 0x49,
  0x43, 0x54, 0x5f, 0x41, 0x50, 0x52, 0x49, 0x4c, 0x54, 0x41, 0x47, 0x5f,
  0x33, 0x36, 0x68, 0x31, 0x30, 0x00, 0x02, 0x32, 0x30, 0x00, 0x14, 0x00,
  0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x41, 0x50, 0x52, 0x49, 0x4c,
  0x54, 0x41, 0x47, 0x5f, 0x33, 0x36, 0x68, 0x31, 0x31, 0x00, 0x00, 0x00,
  0x03, 0x6d, 0x61, 0x72, 0x6b, 0x65, 0x72, 0x5f, 0x69, 0x64, 0x00, 0x17,
  0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x08, 0x00, 0x00,
  0x00, 0x69, 0x6e, 0x74, 0x65, 0x67, 0x65, 0x72, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x63, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e,
  0x5f, 0x66, 0x72, 0x61, 0x6d, 0x65, 0x73, 0x00, 0x28, 0x00, 0x00, 0x00,
  0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x08, 0x00, 0x00, 0x00, 0x69, 0x6e,
  0x74, 0x65, 0x67, 0x65, 0x72, 0x00, 0x01, 0x6d, 0x69, 0x6e, 0x69, 0x6d,
  0x75, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x63, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e,
  0x5f, 0x72, 0x61, 0x6e, 0x67, 0x65, 0x00, 0xaa, 0x00, 0x00, 0x00, 0x03,
  0x70, 0x72, 0x6f, 0x70, 0x65, 0x72, 0x74, 0x69, 0x65, 0x73, 0x00, 0x61,
  0x00, 0x00, 0x00, 0x03, 0x65, 0x6e, 0x64, 0x00, 0x28, 0x00, 0x00, 0x00,
  0x01, 0x6d, 0x69, 0x6e, 0x69, 0x6d, 0x75, 0x6d, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x08,
  0x00, 0x00, 0x00, 0x69, 0x6e, 0x74, 0x65, 0x67, 0x65, 0x72, 0x00, 0x00,
  0x03, 0x62, 0x65, 0x67, 0x69, 0x6e, 0x00, 0x28, 0x00, 0x00, 0x00, 0x02,
  0x74, 0x79, 0x70, 0x65, 0x00, 0x08, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x74,
  0x65, 0x67, 0x65, 0x72, 0x00, 0x01, 0x6d, 0x69, 0x6e, 0x69, 0x6d, 0x75,
  0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x04, 0x72, 0x65, 0x71, 0x75, 0x69, 0x72, 0x65, 0x64, 0x00, 0x1d, 0x00,
  0x00, 0x00, 0x02, 0x30, 0x00, 0x06, 0x00, 0x00, 0x00, 0x62, 0x65, 0x67,
  0x69, 0x6e, 0x00, 0x02, 0x31, 0x00, 0x04, 0x00, 0x00, 0x00, 0x65, 0x6e,
  0x64, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x07, 0x00, 0x00,
  0x00, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x00, 0x00, 0x03, 0x64, 0x6f,
  0x77, 0x6e, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x5f, 0x77, 0x69, 0x64,
  0x74, 0x68, 0x00, 0x28, 0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65,
  0x00, 0x08, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x74, 0x65, 0x67, 0x65, 0x72,
  0x00, 0x01, 0x6d, 0x69, 0x6e, 0x69, 0x6d, 0x75, 0x6d, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0xf0, 0x3f, 0x00, 0x03, 0x75, 0x73, 0x65, 0x5f,
  0x74, 0x68, 0x72, 0x65, 0x61, 0x64, 0x69, 0x6e, 0x67, 0x00, 0x17, 0x00,
  0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x62, 0x6f, 0x6f, 0x6c, 0x65, 0x61, 0x6e, 0x00, 0x00, 0x03, 0x75, 0x73,
  0x65, 0x5f, 0x63, 0x75, 0x64, 0x61, 0x00, 0x17, 0x00, 0x00, 0x00, 0x02,
  0x74, 0x79, 0x70, 0x65, 0x00, 0x08, 0x00, 0x00, 0x00, 0x62, 0x6f, 0x6f,
  0x6c, 0x65, 0x61, 0x6e, 0x00, 0x00, 0x03, 0x64, 0x6f, 0x77, 0x6e, 0x73,
  0x61, 0x6d, 0x70, 0x6c, 0x65, 0x5f, 0x73, 0x63, 0x61, 0x6c, 0x65, 0x00,
  0x16, 0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x07, 0x00,
  0x00, 0x00, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x00, 0x00, 0x03, 0x75,
  0x73, 0x65, 0x5f, 0x70, 0x6f, 0x73, 0x65, 0x5f, 0x6d, 0x65, 0x61, 0x6e,
  0x73, 0x00, 0x17, 0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00,
  0x08, 0x00, 0x00, 0x00, 0x62, 0x6f, 0x6f, 0x6c, 0x65, 0x61, 0x6e, 0x00,
  0x00, 0x03, 0x63, 0x68, 0x61, 0x72, 0x75, 0x63, 0x6f, 0x5f, 0x70, 0x72,
  0x6f, 0x70, 0x65, 0x72, 0x74, 0x69, 0x65, 0x73, 0x00, 0x91, 0x03, 0x00,
  0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x07, 0x00, 0x00, 0x00, 0x6f,
  0x62, 0x6a, 0x65, 0x63, 0x74, 0x00, 0x03, 0x70, 0x72, 0x6f, 0x70, 0x65,
  0x72, 0x74, 0x69, 0x65, 0x73, 0x00, 0xda, 0x02, 0x00, 0x00, 0x03, 0x63,
  0x68, 0x61, 0x72, 0x75, 0x63, 0x6f, 0x5f, 0x73, 0x71, 0x75, 0x61, 0x72,
  0x65, 0x73, 0x5f, 0x78, 0x00, 0x28, 0x00, 0x00, 0x00, 0x01, 0x6d, 0x69,
  0x6e, 0x69, 0x6d, 0x75, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x08, 0x40, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x69, 0x6e, 0x74, 0x65, 0x67, 0x65, 0x72, 0x00, 0x00, 0x03, 0x63, 0x68,
  0x61, 0x72, 0x75, 0x63, 0x6f, 0x5f, 0x73, 0x71, 0x75, 0x61, 0x72, 0x65,
  0x73, 0x5f, 0x79, 0x00, 0x28, 0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70,
  0x65, 0x00, 0x08, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x74, 0x65, 0x67, 0x65,
  0x72, 0x00, 0x01, 0x6d, 0x69, 0x6e, 0x69, 0x6d, 0x75, 0x6d, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, 0x00, 0x03, 0x63, 0x68, 0x61,
  0x72, 0x75, 0x63, 0x6f, 0x5f, 0x73, 0x71, 0x75, 0x61, 0x72, 0x65, 0x5f,
  0x6c, 0x65, 0x6e, 0x67, 0x74, 0x68, 0x00, 0x16, 0x00, 0x00, 0x00, 0x02,
  0x74, 0x79, 0x70, 0x65, 0x00, 0x07, 0x00, 0x00, 0x00, 0x6e, 0x75, 0x6d,
  0x62, 0x65, 0x72, 0x00, 0x00, 0x03, 0x63, 0x68, 0x61, 0x72, 0x75, 0x63,
  0x6f, 0x5f, 0x6d, 0x61, 0x72, 0x6b, 0x65, 0x72, 0x5f, 0x6c, 0x65, 0x6e,
  0x67, 0x74, 0x68, 0x00, 0x16, 0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70,
  0x65, 0x00, 0x07, 0x00, 0x00, 0x00, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72,
  0x00, 0x00, 0x03, 0x63, 0x68, 0x61, 0x72, 0x75, 0x63, 0x6f, 0x5f, 0x64,
  0x69, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x61, 0x72, 0x79, 0x00, 0xf1, 0x01,
  0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x73, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x00, 0x04, 0x65, 0x6e, 0x75, 0x6d,
  0x00, 0xd5, 0x01, 0x00, 0x00, 0x02, 0x30, 0x00, 0x0c, 0x00, 0x00, 0x00,
  0x44, 0x49, 0x43, 0x54, 0x5f, 0x34, 0x58, 0x34, 0x5f, 0x35, 0x30, 0x00,
  0x02, 0x31, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f,
  0x34, 0x58, 0x34, 0x5f, 0x31, 0x30, 0x30, 0x00, 0x02, 0x32, 0x00, 0x0d,
  0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x34, 0x58, 0x34, 0x5f,
  0x32, 0x35, 0x30, 0x00, 0x02, 0x33, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x44,
  0x49, 0x43, 0x54, 0x5f, 0x34, 0x58, 0x34, 0x5f, 0x31, 0x30, 0x30, 0x30,
  0x00, 0x02, 0x34, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54,
  0x5f, 0x35, 0x58, 0x35, 0x5f, 0x35, 0x30, 0x00, 0x02, 0x35, 0x00, 0x0d,
  0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x35, 0x58, 0x35, 0x5f,
  0x31, 0x30, 0x30, 0x00, 0x02, 0x36, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x44,
  0x49, 0x43, 0x54, 0x5f, 0x35, 0x58, 0x35, 0x5f, 0x32, 0x35, 0x30, 0x00,
  0x02, 0x37, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f,
  0x35, 0x58, 0x35, 0x5f, 0x31, 0x30, 0x30, 0x30, 0x00, 0x02, 0x38, 0x00,
  0x0c, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x36, 0x58, 0x36,
  0x5f, 0x35, 0x30, 0x00, 0x02, 0x39, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x44,
  0x49, 0x43, 0x54, 0x5f, 0x36, 0x58, 0x36, 0x5f, 0x31, 0x30, 0x30, 0x00,
  0x02, 0x31, 0x30, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54,
  0x5f, 0x36, 0x58, 0x36, 0x5f, 0x32, 0x35, 0x30, 0x00, 0x02, 0x31, 0x31,
  0x00, 0x0e, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x36, 0x58,
  0x36, 0x5f, 0x31, 0x30, 0x30, 0x30, 0x00, 0x02, 0x31, 0x32, 0x00, 0x0c,
  0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x37, 0x58, 0x37, 0x5f,
  0x35, 0x30, 0x00, 0x02, 0x31, 0x33, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x44,
  0x49, 0x43, 0x54, 0x5f, 0x37, 0x58, 0x37, 0x5f, 0x31, 0x30, 0x30, 0x00,
  0x02, 0x31, 0x34, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54,
  0x5f, 0x37, 0x58, 0x37, 0x5f, 0x32, 0x35, 0x30, 0x00, 0x02, 0x31, 0x35,
  0x00, 0x0e, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x37, 0x58,
  0x37, 0x5f, 0x31, 0x30, 0x30, 0x30, 0x00, 0x02, 0x31, 0x36, 0x00, 0x14,
  0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x41, 0x52, 0x55, 0x43,
  0x4f, 0x5f, 0x4f, 0x52, 0x49, 0x47, 0x49, 0x4e, 0x41, 0x4c, 0x00, 0x02,
  0x31, 0x37, 0x00, 0x13, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f,
  0x41, 0x50, 0x52, 0x49, 0x4c, 0x54, 0x41, 0x47, 0x5f, 0x31, 0x36, 0x68,
  0x35, 0x00, 0x02, 0x31, 0x38, 0x00, 0x13, 0x00, 0x00, 0x00, 0x44, 0x49,
  0x43, 0x54, 0x5f, 0x41, 0x50, 0x52, 0x49, 0x4c, 0x54, 0x41, 0x47, 0x5f,
  0x32, 0x35, 0x68, 0x39, 0x00, 0x02, 0x31, 0x39, 0x00, 0x14, 0x00, 0x00,
  0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x41, 0x50, 0x52, 0x49, 0x4c, 0x54,
  0x41, 0x47, 0x5f, 0x33, 0x36, 0x68, 0x31, 0x30, 0x00, 0x02, 0x32, 0x30,
  0x00, 0x14, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x41, 0x50,
  0x52, 0x49, 0x4c, 0x54, 0x41, 0x47, 0x5f, 0x33, 0x36, 0x68, 0x31, 0x31,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x72, 0x65, 0x71, 0x75, 0x69, 0x72, 0x65,
  0x64, 0x00, 0x8b, 0x00, 0x00, 0x00, 0x02, 0x30, 0x00, 0x13, 0x00, 0x00,
  0x00, 0x63, 0x68, 0x61, 0x72, 0x75, 0x63, 0x6f, 0x5f, 0x64, 0x69, 0x63,
  0x74, 0x69, 0x6f, 0x6e, 0x61, 0x72, 0x79, 0x00, 0x02, 0x31, 0x00, 0x12,
  0x00, 0x00, 0x00, 0x63, 0x68, 0x61, 0x72, 0x75, 0x63, 0x6f, 0x5f, 0x73,
  0x71, 0x75, 0x61, 0x72, 0x65, 0x73, 0x5f, 0x78, 0x00, 0x02, 0x32, 0x00,
  0x12, 0x00, 0x00, 0x00, 0x63, 0x68, 0x61, 0x72, 0x75, 0x63, 0x6f, 0x5f,
  0x73, 0x71, 0x75, 0x61, 0x72, 0x65, 0x73, 0x5f, 0x79, 0x00, 0x02, 0x33,
  0x00, 0x16, 0x00, 0x00, 0x00, 0x63, 0x68, 0x61, 0x72, 0x75, 0x63, 0x6f,
  0x5f, 0x73, 0x71, 0x75, 0x61, 0x72, 0x65, 0x5f, 0x6c, 0x65, 0x6e, 0x67,
  0x74, 0x68, 0x00, 0x02, 0x34, 0x00, 0x16, 0x00, 0x00, 0x00, 0x63, 0x68,
  0x61, 0x72, 0x75, 0x63, 0x6f, 0x5f, 0x6d, 0x61, 0x72, 0x6b, 0x65, 0x72,
  0x5f, 0x6c, 0x65, 0x6e, 0x67, 0x74, 0x68, 0x00, 0x00, 0x00, 0x03, 0x73,
  0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x65, 0x5f, 0x74, 0x79, 0x70, 0x65,
  0x00, 0x3c, 0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x07,
  0x00, 0x00, 0x00, 0x73, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x00, 0x04, 0x65,
  0x6e, 0x75, 0x6d, 0x00, 0x20, 0x00, 0x00, 0x00, 0x02, 0x30, 0x00, 0x06,
  0x00, 0x00, 0x00, 0x76, 0x69, 0x64, 0x65, 0x6f, 0x00, 0x02, 0x31, 0x00,
  0x07, 0x00, 0x00, 0x00, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x73, 0x00, 0x00,
  0x00, 0x03, 0x63, 0x61, 0x6c, 0x69, 0x62, 0x72, 0x61, 0x74, 0x65, 0x5f,
  0x63, 0x61, 0x6d, 0x65, 0x72, 0x61, 0x00, 0x17, 0x00, 0x00, 0x00, 0x02,
  0x74, 0x79, 0x70, 0x65, 0x00, 0x08, 0x00, 0x00, 0x00, 0x62, 0x6f, 0x6f,
  0x6c, 0x65, 0x61, 0x6e, 0x00, 0x00, 0x03, 0x61, 0x6e, 0x61, 0x6c, 0x79,
  0x73, 0x69, 0x73, 0x5f, 0x72, 0x61, 0x6e, 0x67, 0x65, 0x00, 0xaa, 0x00,
  0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x07, 0x00, 0x00, 0x00,
  0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x00, 0x03, 0x70, 0x72, 0x6f, 0x70,
  0x65, 0x72, 0x74, 0x69, 0x65, 0x73, 0x00, 0x61, 0x00, 0x00, 0x00, 0x03,
  0x62, 0x65, 0x67, 0x69, 0x6e, 0x00, 0x28, 0x00, 0x00, 0x00, 0x02, 0x74,
  0x79, 0x70, 0x65, 0x00, 0x08, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x74, 0x65,
  0x67, 0x65, 0x72, 0x00, 0x01, 0x6d, 0x69, 0x6e, 0x69, 0x6d, 0x75, 0x6d,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x65,
  0x6e, 0x64, 0x00, 0x28, 0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65,
  0x00, 0x08, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x74, 0x65, 0x67, 0x65, 0x72,
  0x00, 0x01, 0x6d, 0x69, 0x6e, 0x69, 0x6d, 0x75, 0x6d, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x72, 0x65, 0x71,
  0x75, 0x69, 0x72, 0x65, 0x64, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x02, 0x30,
  0x00, 0x06, 0x00, 0x00, 0x00, 0x62, 0x65, 0x67, 0x69, 0x6e, 0x00, 0x02,
  0x31, 0x00, 0x04, 0x00, 0x00, 0x00, 0x65, 0x6e, 0x64, 0x00, 0x00, 0x00,
  0x03, 0x6d, 0x61, 0x72, 0x6b, 0x65, 0x72, 0x5f, 0x70, 0x72, 0x6f, 0x70,
  0x65, 0x72, 0x74, 0x69, 0x65, 0x73, 0x00, 0xcc, 0x02, 0x00, 0x00, 0x02,
  0x74, 0x79, 0x70, 0x65, 0x00, 0x07, 0x00, 0x00, 0x00, 0x6f, 0x62, 0x6a,
  0x65, 0x63, 0x74, 0x00, 0x03, 0x70, 0x72, 0x6f, 0x70, 0x65, 0x72, 0x74,
  0x69, 0x65, 0x73, 0x00, 0x6d, 0x02, 0x00, 0x00, 0x03, 0x6d, 0x61, 0x72,
  0x6b, 0x65, 0x72, 0x5f, 0x64, 0x69, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x61,
  0x72, 0x79, 0x00, 0xf1, 0x01, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65,
  0x00, 0x07, 0x00, 0x00, 0x00, 0x73, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x00,
  0x04, 0x65, 0x6e, 0x75, 0x6d, 0x00, 0xd5, 0x01, 0x00, 0x00, 0x02, 0x30,
  0x00, 0x0c, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x34, 0x58,
  0x34, 0x5f, 0x35, 0x30, 0x00, 0x02, 0x31, 0x00, 0x0d, 0x00, 0x00, 0x00,
  0x44, 0x49, 0x43, 0x54, 0x5f, 0x34, 0x58, 0x34, 0x5f, 0x31, 0x30, 0x30,
  0x00, 0x02, 0x32, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54,
  0x5f, 0x34, 0x58, 0x34, 0x5f, 0x32, 0x35, 0x30, 0x00, 0x02, 0x33, 0x00,
  0x0e, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x34, 0x58, 0x34,
  0x5f, 0x31, 0x30, 0x30, 0x30, 0x00, 0x02, 0x34, 0x00, 0x0c, 0x00, 0x00,
  0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x35, 0x58, 0x35, 0x5f, 0x35, 0x30,
  0x00, 0x02, 0x35, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54,
  0x5f, 0x35, 0x58, 0x35, 0x5f, 0x31, 0x30, 0x30, 0x00, 0x02, 0x36, 0x00,
  0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x35, 0x58, 0x35,
  0x5f, 0x32, 0x35, 0x30, 0x00, 0x02, 0x37, 0x00, 0x0e, 0x00, 0x00, 0x00,
  0x44, 0x49, 0x43, 0x54, 0x5f, 0x35, 0x58, 0x35, 0x5f, 0x31, 0x30, 0x30,
  0x30, 0x00, 0x02, 0x38, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43,
  0x54, 0x5f, 0x36, 0x58, 0x36, 0x5f, 0x35, 0x30, 0x00, 0x02, 0x39, 0x00,
  0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x36, 0x58, 0x36,
  0x5f, 0x31, 0x30, 0x30, 0x00, 0x02, 0x31, 0x30, 0x00, 0x0d, 0x00, 0x00,
  0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x36, 0x58, 0x36, 0x5f, 0x32, 0x35,
  0x30, 0x00, 0x02, 0x31, 0x31, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x44, 0x49,
  0x43, 0x54, 0x5f, 0x36, 0x58, 0x36, 0x5f, 0x31, 0x30, 0x30, 0x30, 0x00,
  0x02, 0x31, 0x32, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54,
  0x5f, 0x37, 0x58, 0x37, 0x5f, 0x35, 0x30, 0x00, 0x02, 0x31, 0x33, 0x00,
  0x0d, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x37, 0x58, 0x37,
  0x5f, 0x31, 0x30, 0x30, 0x00, 0x02, 0x31, 0x34, 0x00, 0x0d, 0x00, 0x00,
  0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x37, 0x58, 0x37, 0x5f, 0x32, 0x35,
  0x30, 0x00, 0x02, 0x31, 0x35, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x44, 0x49,
  0x43, 0x54, 0x5f, 0x37, 0x58, 0x37, 0x5f, 0x31, 0x30, 0x30, 0x30, 0x00,
  0x02, 0x31, 0x36, 0x00, 0x14, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54,
  0x5f, 0x41, 0x52, 0x55, 0x43, 0x4f, 0x5f, 0x4f, 0x52, 0x49, 0x47, 0x49,
  0x4e, 0x41, 0x4c, 0x00, 0x02, 0x31, 0x37, 0x00, 0x13, 0x00, 0x00, 0x00,
  0x44, 0x49, 0x43, 0x54, 0x5f, 0x41, 0x50, 0x52, 0x49, 0x4c, 0x54, 0x41,
  0x47, 0x5f, 0x31, 0x36, 0x68, 0x35, 0x00, 0x02, 0x31, 0x38, 0x00, 0x13,
  0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x41, 0x50, 0x52, 0x49,
  0x4c, 0x54, 0x41, 0x47, 0x5f, 0x32, 0x35, 0x68, 0x39, 0x00, 0x02, 0x31,
  0x39, 0x00, 0x14, 0x00, 0x00, 0x00, 0x44, 0x49, 0x43, 0x54, 0x5f, 0x41,
  0x50, 0x52, 0x49, 0x4c, 0x54, 0x41, 0x47, 0x5f, 0x33, 0x36, 0x68, 0x31,
  0x30, 0x00, 0x02, 0x32, 0x30, 0x00, 0x14, 0x00, 0x00, 0x00, 0x44, 0x49,
  0x43, 0x54, 0x5f, 0x41, 0x50, 0x52, 0x49, 0x4c, 0x54, 0x41, 0x47, 0x5f,
  0x33, 0x36, 0x68, 0x31, 0x31, 0x00, 0x00, 0x00, 0x03, 0x6d, 0x61, 0x72,
  0x6b, 0x65, 0x72, 0x5f, 0x6c, 0x65, 0x6e, 0x67, 0x74, 0x68, 0x00, 0x16,
  0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x07, 0x00, 0x00,
  0x00, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x00, 0x00, 0x03, 0x6d, 0x61,
  0x72, 0x6b, 0x65, 0x72, 0x5f, 0x69, 0x64, 0x73, 0x00, 0x33, 0x00, 0x00,
  0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x06, 0x00, 0x00, 0x00, 0x61,
  0x72, 0x72, 0x61, 0x79, 0x00, 0x03, 0x69, 0x74, 0x65, 0x6d, 0x73, 0x00,
  0x17, 0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x08, 0x00,
  0x00, 0x00, 0x69, 0x6e, 0x74, 0x65, 0x67, 0x65, 0x72, 0x00, 0x00, 0x00,
  0x00, 0x04, 0x72, 0x65, 0x71, 0x75, 0x69, 0x72, 0x65, 0x64, 0x00, 0x33,
  0x00, 0x00, 0x00, 0x02, 0x30, 0x00, 0x12, 0x00, 0x00, 0x00, 0x6d, 0x61,
  0x72, 0x6b, 0x65, 0x72, 0x5f, 0x64, 0x69, 0x63, 0x74, 0x69, 0x6f, 0x6e,
  0x61, 0x72, 0x79, 0x00, 0x02, 0x31, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x6d,
  0x61, 0x72, 0x6b, 0x65, 0x72, 0x5f, 0x6c, 0x65, 0x6e, 0x67, 0x74, 0x68,
  0x00, 0x00, 0x00, 0x03, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x65,
  0x5f, 0x66, 0x69, 0x6c, 0x65, 0x73, 0x00, 0x44, 0x00, 0x00, 0x00, 0x02,
  0x74, 0x79, 0x70, 0x65, 0x00, 0x06, 0x00, 0x00, 0x00, 0x61, 0x72, 0x72,
  0x61, 0x79, 0x00, 0x01, 0x6d, 0x69, 0x6e, 0x49, 0x74, 0x65, 0x6d, 0x73,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x3f, 0x03, 0x69, 0x74,
  0x65, 0x6d, 0x73, 0x00, 0x16, 0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70,
  0x65, 0x00, 0x07, 0x00, 0x00, 0x00, 0x73, 0x74, 0x72, 0x69, 0x6e, 0x67,
  0x00, 0x00, 0x00, 0x03, 0x70, 0x61, 0x74, 0x74, 0x65, 0x72, 0x6e, 0x5f,
  0x64, 0x69, 0x6d, 0x65, 0x6e, 0x73, 0x69, 0x6f, 0x6e, 0x73, 0x00, 0xb0,
  0x00, 0x00, 0x00, 0x02, 0x74, 0x79, 0x70, 0x65, 0x00, 0x07, 0x00, 0x00,
  0x00, 0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x00, 0x03, 0x70, 0x72, 0x6f,
  0x70, 0x65, 0x72, 0x74, 0x69, 0x65, 0x73, 0x00, 0x64, 0x00, 0x00, 0x00,
  0x03, 0x77, 0x69, 0x64, 0x74, 0x68, 0x00, 0x28, 0x00, 0x00, 0x00, 0x02,
  0x74, 0x79, 0x70, 0x65, 0x00, 0x08, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x74,
  0x65, 0x67, 0x65, 0x72, 0x00, 0x01, 0x6d, 0x69, 0x6e, 0x69, 0x6d, 0x75,
  0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x03,
  0x68, 0x65, 0x69, 0x67, 0x68, 0x74, 0x00, 0x28, 0x00, 0x00, 0x00, 0x02,
  0x74, 0x79, 0x70, 0x65, 0x00, 0x08, 0x00, 0x00, 0x00, 0x69, 0x6e, 0x74,
  0x65, 0x67, 0x65, 0x72, 0x00, 0x01, 0x6d, 0x69, 0x6e, 0x69, 0x6d, 0x75,
  0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
  0x04, 0x72, 0x65, 0x71, 0x75, 0x69, 0x72, 0x65, 0x64, 0x00, 0x20, 0x00,
  0x00, 0x00, 0x02, 0x30, 0x00, 0x06, 0x00, 0x00, 0x00, 0x77, 0x69, 0x64,
  0x74, 0x68, 0x00, 0x02, 0x31, 0x00, 0x07, 0x00, 0x00, 0x00, 0x68, 0x65,
  0x69, 0x67, 0x68, 0x74, 0x00, 0x00, 0x00, 0x00, 0x04, 0x72, 0x65, 0x71,
  0x75, 0x69, 0x72, 0x65, 0x64, 0x00, 0x30, 0x00, 0x00, 0x00, 0x02, 0x30,
  0x00, 0x0e, 0x00, 0x00, 0x00, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63,
  0x65, 0x5f, 0x74, 0x79, 0x70, 0x65, 0x00, 0x02, 0x31, 0x00, 0x0f, 0x00,
  0x00, 0x00, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x65, 0x5f, 0x66,
  0x69, 0x6c, 0x65, 0x73, 0x00, 0x00, 0x03, 0x64, 0x65, 0x70, 0x65, 0x6e,
  0x64, 0x65, 0x6e, 0x63, 0x69, 0x65, 0x73, 0x00, 0xc7, 0x01, 0x00, 0x00,
  0x03, 0x64, 0x6f, 0x77, 0x6e, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x5f,
  0x68, 0x65, 0x69, 0x67, 0x68, 0x74, 0x00, 0x83, 0x00, 0x00, 0x00, 0x04,
  0x61, 0x6c, 0x6c, 0x4f, 0x66, 0x00, 0x77, 0x00, 0x00, 0x00, 0x03, 0x30,
  0x00, 0x36, 0x00, 0x00, 0x00, 0x03, 0x6e, 0x6f, 0x74, 0x00, 0x2c, 0x00,
  0x00, 0x00, 0x04, 0x72, 0x65, 0x71, 0x75, 0x69, 0x72, 0x65, 0x64, 0x00,
  0x1d, 0x00, 0x00, 0x00, 0x02, 0x30, 0x00, 0x11, 0x00, 0x00, 0x00, 0x64,
  0x6f, 0x77, 0x6e, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x5f, 0x77, 0x69,
  0x64, 0x74, 0x68, 0x00, 0x00, 0x00, 0x00, 0x03, 0x31, 0x00, 0x36, 0x00,
  0x00, 0x00, 0x03, 0x6e, 0x6f, 0x74, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x04,
  0x72, 0x65, 0x71, 0x75, 0x69, 0x72, 0x65, 0x64, 0x00, 0x1d, 0x00, 0x00,
  0x00, 0x02, 0x30, 0x00, 0x11, 0x00, 0x00, 0x00, 0x64, 0x6f, 0x77, 0x6e,
  0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x5f, 0x73, 0x63, 0x61, 0x6c, 0x65,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x64, 0x6f, 0x77, 0x6e, 0x73,
  0x61, 0x6d, 0x70, 0x6c, 0x65, 0x5f, 0x73, 0x63, 0x61, 0x6c, 0x65, 0x00,
  0x84, 0x00, 0x00, 0x00, 0x04, 0x61, 0x6c, 0x6c, 0x4f, 0x66, 0x00, 0x78,
  0x00, 0x00, 0x00, 0x03, 0x30, 0x00, 0x36, 0x00, 0x00, 0x00, 0x03, 0x6e,
  0x6f, 0x74, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x04, 0x72, 0x65, 0x71, 0x75,
  0x69, 0x72, 0x65, 0x64, 0x00, 0x1d, 0x00, 0x00, 0x00, 0x02, 0x30, 0x00,
  0x11, 0x00, 0x00, 0x00, 0x64, 0x6f, 0x77, 0x6e, 0x73, 0x61, 0x6d, 0x70,
  0x6c, 0x65, 0x5f, 0x77, 0x69, 0x64, 0x74, 0x68, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x31, 0x00, 0x37, 0x00, 0x00, 0x00, 0x03, 0x6e, 0x6f, 0x74, 0x00,
  0x2d, 0x00, 0x00, 0x00, 0x04, 0x72, 0x65, 0x71, 0x75, 0x69, 0x72, 0x65,
  0x64, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x02, 0x30, 0x00, 0x12, 0x00, 0x00,
  0x00, 0x64, 0x6f, 0x77, 0x6e, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x5f,
  0x68, 0x65, 0x69, 0x67, 0x68, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x64, 0x6f, 0x77, 0x6e, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x5f,
  0x77, 0x69, 0x64, 0x74, 0x68, 0x00, 0x84, 0x00, 0x00, 0x00, 0x04, 0x61,
  0x6c, 0x6c, 0x4f, 0x66, 0x00, 0x78, 0x00, 0x00, 0x00, 0x03, 0x30, 0x00,
  0x36, 0x00, 0x00, 0x00, 0x03, 0x6e, 0x6f, 0x74, 0x00, 0x2c, 0x00, 0x00,
  0x00, 0x04, 0x72, 0x65, 0x71, 0x75, 0x69, 0x72, 0x65, 0x64, 0x00, 0x1d,
  0x00, 0x00, 0x00, 0x02, 0x30, 0x00, 0x11, 0x00, 0x00, 0x00, 0x64, 0x6f,
  0x77, 0x6e, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x5f, 0x73, 0x63, 0x61,
  0x6c, 0x65, 0x00, 0x00, 0x00, 0x00, 0x03, 0x31, 0x00, 0x37, 0x00, 0x00,
  0x00, 0x03, 0x6e, 0x6f, 0x74, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x04, 0x72,
  0x65, 0x71, 0x75, 0x69, 0x72, 0x65, 0x64, 0x00, 0x1e, 0x00, 0x00, 0x00,
  0x02, 0x30, 0x00, 0x12, 0x00, 0x00, 0x00, 0x64, 0x6f, 0x77, 0x6e, 0x73,
  0x61, 0x6d, 0x70, 0x6c, 0x65, 0x5f, 0x68, 0x65, 0x69, 0x67, 0x68, 0x74,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

unsigned int calibration_config_bson_len = 4088;