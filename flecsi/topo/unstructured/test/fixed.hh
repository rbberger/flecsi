/*
    @@@@@@@@  @@           @@@@@@   @@@@@@@@ @@
   /@@/////  /@@          @@////@@ @@////// /@@
   /@@       /@@  @@@@@  @@    // /@@       /@@
   /@@@@@@@  /@@ @@///@@/@@       /@@@@@@@@@/@@
   /@@////   /@@/@@@@@@@/@@       ////////@@/@@
   /@@       /@@/@@//// //@@    @@       /@@/@@
   /@@       @@@//@@@@@@ //@@@@@@  @@@@@@@@ /@@
   //       ///  //////   //////  ////////  //

   Copyright (c) 2016, Triad National Security, LLC
   All rights reserved.
                                                                              */
#pragma once

#include "flecsi/topo/unstructured/types.hh"

#include <vector>

namespace ftui = flecsi::topo::unstructured_impl;

namespace fixed {

constexpr flecsi::Color colors = 4;
constexpr std::size_t num_cells = 256;
constexpr std::size_t num_vertices = 289;

// clang-format off
inline std::vector<std::vector<ftui::crs>> connectivity = {
  { /* color 0 */
    { /* cell -> vertex */
      { /* offsets */
          0,   4,   8,  12,  16,  20,  24,  28,  32,  36,  40,  44,  48,  52,
         56,  60,  64,  68,  72,  76,  80,  84,  88,  92,  96, 100, 104, 108,
        112, 116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156, 160, 164,
        168, 172, 176, 180, 184, 188, 192, 196, 200, 204, 208, 212, 216, 220,
        224, 228, 232, 236, 240, 244, 248, 252, 256, 260, 264, 268, 272, 276,
        280, 284, 288, 292, 296, 300, 304, 308, 312, 316, 320, 324
      },
      { /* indices */
          7,   8,  25,  24,
          8,   9,  26,  25,
          9,  10,  27,  26,
         10,  11,  28,  27,
         11,  12,  29,  28,
         12,  13,  30,  29,
         13,  14,  31,  30,
         14,  15,  32,  31,
         15,  16,  33,  32,
         24,  25,  42,  41,
         25,  26,  43,  42,
         26,  27,  44,  43,
         27,  28,  45,  44,
         28,  29,  46,  45,
         29,  30,  47,  46,
         30,  31,  48,  47,
         31,  32,  49,  48,
         32,  33,  50,  49,
         41,  42,  59,  58,
         42,  43,  60,  59,
         43,  44,  61,  60,
         44,  45,  62,  61,
         45,  46,  63,  62,
         46,  47,  64,  63,
         47,  48,  65,  64,
         48,  49,  66,  65,
         49,  50,  67,  66,
         58,  59,  76,  75,
         59,  60,  77,  76,
         60,  61,  78,  77,
         61,  62,  79,  78,
         62,  63,  80,  79,
         63,  64,  81,  80,
         64,  65,  82,  81,
         65,  66,  83,  82,
         66,  67,  84,  83,
         75,  76,  93,  92,
         76,  77,  94,  93,
         77,  78,  95,  94,
         78,  79,  96,  95,
         79,  80,  97,  96,
         80,  81,  98,  97,
         81,  82,  99,  98,
         82,  83, 100,  99,
         83,  84, 101, 100,
         92,  93, 110, 109,
         93,  94, 111, 110,
         94,  95, 112, 111,
         95,  96, 113, 112,
         96,  97, 114, 113,
         97,  98, 115, 114,
         98,  99, 116, 115,
         99, 100, 117, 116,
        100, 101, 118, 117,
        109, 110, 127, 126,
        110, 111, 128, 127,
        111, 112, 129, 128,
        112, 113, 130, 129,
        113, 114, 131, 130,
        114, 115, 132, 131,
        115, 116, 133, 132,
        116, 117, 134, 133,
        117, 118, 135, 134,
        126, 127, 144, 143,
        127, 128, 145, 144,
        128, 129, 146, 145,
        129, 130, 147, 146,
        130, 131, 148, 147,
        131, 132, 149, 148,
        132, 133, 150, 149,
        133, 134, 151, 150,
        134, 135, 152, 151,
        143, 144, 161, 160,
        144, 145, 162, 161,
        145, 146, 163, 162,
        146, 147, 164, 163,
        147, 148, 165, 164,
        148, 149, 166, 165,
        149, 150, 167, 166,
        150, 151, 168, 167,
        151, 152, 169, 168
      }
    }
  },
  { /* color 1 */
    { /* cell -> vertex */
      { /* offsets */
          0,   4,   8,  12,  16,  20,  24,  28,  32,  36,  40,  44,  48,  52,
         56,  60,  64,  68,  72,  76,  80,  84,  88,  92,  96, 100, 104, 108,
        112, 116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156, 160, 164,
        168, 172, 176, 180, 184, 188, 192, 196, 200, 204, 208, 212, 216, 220,
        224, 228, 232, 236, 240, 244, 248, 252, 256, 260, 264, 268, 272, 276,
        280, 284, 288, 292, 296, 300, 304, 308, 312, 316, 320, 324
      },
      { /* indices */
          0,   1,  18,  17,
          1,   2,  19,  18,
          2,   3,  20,  19,
          3,   4,  21,  20,
          4,   5,  22,  21,
          5,   6,  23,  22,
          6,   7,  24,  23,
          7,   8,  25,  24,
          8,   9,  26,  25,
         17,  18,  35,  34,
         18,  19,  36,  35,
         19,  20,  37,  36,
         20,  21,  38,  37,
         21,  22,  39,  38,
         22,  23,  40,  39,
         23,  24,  41,  40,
         24,  25,  42,  41,
         25,  26,  43,  42,
         34,  35,  52,  51,
         35,  36,  53,  52,
         36,  37,  54,  53,
         37,  38,  55,  54,
         38,  39,  56,  55,
         39,  40,  57,  56,
         40,  41,  58,  57,
         41,  42,  59,  58,
         42,  43,  60,  59,
         51,  52,  69,  68,
         52,  53,  70,  69,
         53,  54,  71,  70,
         54,  55,  72,  71,
         55,  56,  73,  72,
         56,  57,  74,  73,
         57,  58,  75,  74,
         58,  59,  76,  75,
         59,  60,  77,  76,
         68,  69,  86,  85,
         69,  70,  87,  86,
         70,  71,  88,  87,
         71,  72,  89,  88,
         72,  73,  90,  89,
         73,  74,  91,  90,
         74,  75,  92,  91,
         75,  76,  93,  92,
         76,  77,  94,  93,
         85,  86, 103, 102,
         86,  87, 104, 103,
         87,  88, 105, 104,
         88,  89, 106, 105,
         89,  90, 107, 106,
         90,  91, 108, 107,
         91,  92, 109, 108,
         92,  93, 110, 109,
         93,  94, 111, 110,
        102, 103, 120, 119,
        103, 104, 121, 120,
        104, 105, 122, 121,
        105, 106, 123, 122,
        106, 107, 124, 123,
        107, 108, 125, 124,
        108, 109, 126, 125,
        109, 110, 127, 126,
        110, 111, 128, 127,
        119, 120, 137, 136,
        120, 121, 138, 137,
        121, 122, 139, 138,
        122, 123, 140, 139,
        123, 124, 141, 140,
        124, 125, 142, 141,
        125, 126, 143, 142,
        126, 127, 144, 143,
        127, 128, 145, 144,
        136, 137, 154, 153,
        137, 138, 155, 154,
        138, 139, 156, 155,
        139, 140, 157, 156,
        140, 141, 158, 157,
        141, 142, 159, 158,
        142, 143, 160, 159,
        143, 144, 161, 160,
        144, 145, 162, 161
      }
    }
  },
  { /* color 2 */
    { /* cell -> vertex */
      { /* offsets */
          0,   4,   8,  12,  16,  20,  24,  28,  32,  36,  40,  44,  48,  52,
         56,  60,  64,  68,  72,  76,  80,  84,  88,  92,  96, 100, 104, 108,
        112, 116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156, 160, 164,
        168, 172, 176, 180, 184, 188, 192, 196, 200, 204, 208, 212, 216, 220,
        224, 228, 232, 236, 240, 244, 248, 252, 256, 260, 264, 268, 272, 276,
        280, 284, 288, 292, 296, 300, 304, 308, 312, 316, 320, 324
      },
      { /* indices */
        126, 127, 144, 143,
        127, 128, 145, 144,
        128, 129, 146, 145,
        129, 130, 147, 146,
        130, 131, 148, 147,
        131, 132, 149, 148,
        132, 133, 150, 149,
        133, 134, 151, 150,
        134, 135, 152, 151,
        143, 144, 161, 160,
        144, 145, 162, 161,
        145, 146, 163, 162,
        146, 147, 164, 163,
        147, 148, 165, 164,
        148, 149, 166, 165,
        149, 150, 167, 166,
        150, 151, 168, 167,
        151, 152, 169, 168,
        160, 161, 178, 177,
        161, 162, 179, 178,
        162, 163, 180, 179,
        163, 164, 181, 180,
        164, 165, 182, 181,
        165, 166, 183, 182,
        166, 167, 184, 183,
        167, 168, 185, 184,
        168, 169, 186, 185,
        177, 178, 195, 194,
        178, 179, 196, 195,
        179, 180, 197, 196,
        180, 181, 198, 197,
        181, 182, 199, 198,
        182, 183, 200, 199,
        183, 184, 201, 200,
        184, 185, 202, 201,
        185, 186, 203, 202,
        194, 195, 212, 211,
        195, 196, 213, 212,
        196, 197, 214, 213,
        197, 198, 215, 214,
        198, 199, 216, 215,
        199, 200, 217, 216,
        200, 201, 218, 217,
        201, 202, 219, 218,
        202, 203, 220, 219,
        211, 212, 229, 228,
        212, 213, 230, 229,
        213, 214, 231, 230,
        214, 215, 232, 231,
        215, 216, 233, 232,
        216, 217, 234, 233,
        217, 218, 235, 234,
        218, 219, 236, 235,
        219, 220, 237, 236,
        228, 229, 246, 245,
        229, 230, 247, 246,
        230, 231, 248, 247,
        231, 232, 249, 248,
        232, 233, 250, 249,
        233, 234, 251, 250,
        234, 235, 252, 251,
        235, 236, 253, 252,
        236, 237, 254, 253,
        245, 246, 263, 262,
        246, 247, 264, 263,
        247, 248, 265, 264,
        248, 249, 266, 265,
        249, 250, 267, 266,
        250, 251, 268, 267,
        251, 252, 269, 268,
        252, 253, 270, 269,
        253, 254, 271, 270,
        262, 263, 280, 279,
        263, 264, 281, 280,
        264, 265, 282, 281,
        265, 266, 283, 282,
        266, 267, 284, 283,
        267, 268, 285, 284,
        268, 269, 286, 285,
        269, 270, 287, 286,
        270, 271, 288, 287
      }
    }
  },
  { /* color 3 */
    { /* cell -> vertex */
      { /* offsets */
          0,   4,   8,  12,  16,  20,  24,  28,  32,  36,  40,  44,  48,  52,
         56,  60,  64,  68,  72,  76,  80,  84,  88,  92,  96, 100, 104, 108,
        112, 116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156, 160, 164,
        168, 172, 176, 180, 184, 188, 192, 196, 200, 204, 208, 212, 216, 220,
        224, 228, 232, 236, 240, 244, 248, 252, 256, 260, 264, 268, 272, 276,
        280, 284, 288, 292, 296, 300, 304, 308, 312, 316, 320, 324
      },
      { /* indices */
        119, 120, 137, 136,
        120, 121, 138, 137,
        121, 122, 139, 138,
        122, 123, 140, 139,
        123, 124, 141, 140,
        124, 125, 142, 141,
        125, 126, 143, 142,
        126, 127, 144, 143,
        127, 128, 145, 144,
        136, 137, 154, 153,
        137, 138, 155, 154,
        138, 139, 156, 155,
        139, 140, 157, 156,
        140, 141, 158, 157,
        141, 142, 159, 158,
        142, 143, 160, 159,
        143, 144, 161, 160,
        144, 145, 162, 161,
        153, 154, 171, 170,
        154, 155, 172, 171,
        155, 156, 173, 172,
        156, 157, 174, 173,
        157, 158, 175, 174,
        158, 159, 176, 175,
        159, 160, 177, 176,
        160, 161, 178, 177,
        161, 162, 179, 178,
        170, 171, 188, 187,
        171, 172, 189, 188,
        172, 173, 190, 189,
        173, 174, 191, 190,
        174, 175, 192, 191,
        175, 176, 193, 192,
        176, 177, 194, 193,
        177, 178, 195, 194,
        178, 179, 196, 195,
        187, 188, 205, 204,
        188, 189, 206, 205,
        189, 190, 207, 206,
        190, 191, 208, 207,
        191, 192, 209, 208,
        192, 193, 210, 209,
        193, 194, 211, 210,
        194, 195, 212, 211,
        195, 196, 213, 212,
        204, 205, 222, 221,
        205, 206, 223, 222,
        206, 207, 224, 223,
        207, 208, 225, 224,
        208, 209, 226, 225,
        209, 210, 227, 226,
        210, 211, 228, 227,
        211, 212, 229, 228,
        212, 213, 230, 229,
        221, 222, 239, 238,
        222, 223, 240, 239,
        223, 224, 241, 240,
        224, 225, 242, 241,
        225, 226, 243, 242,
        226, 227, 244, 243,
        227, 228, 245, 244,
        228, 229, 246, 245,
        229, 230, 247, 246,
        238, 239, 256, 255,
        239, 240, 257, 256,
        240, 241, 258, 257,
        241, 242, 259, 258,
        242, 243, 260, 259,
        243, 244, 261, 260,
        244, 245, 262, 261,
        245, 246, 263, 262,
        246, 247, 264, 263,
        255, 256, 273, 272,
        256, 257, 274, 273,
        257, 258, 275, 274,
        258, 259, 276, 275,
        259, 260, 277, 276,
        260, 261, 278, 277,
        261, 262, 279, 278,
        262, 263, 280, 279,
        263, 264, 281, 280
      }
    }
  }
};

inline std::vector<ftui::index_coloring> cells = {
  { /* color 0 */
    { /* all */
        7,   8,   9,  10,  11,  12,  13,  14,  15,
       23,  24,  25,  26,  27,  28,  29,  30,  31,
       39,  40,  41,  42,  43,  44,  45,  46,  47,
       55,  56,  57,  58,  59,  60,  61,  62,  63,
       71,  72,  73,  74,  75,  76,  77,  78,  79,
       87,  88,  89,  90,  91,  92,  93,  94,  95,
      103, 104, 105, 106, 107, 108, 109, 110, 111,
      119, 120, 121, 122, 123, 124, 125, 126, 127,
      135, 136, 137, 138, 139, 140, 141, 142, 143
    },
    { /* owned */
        8,   9,  10,  11,  12,  13,  14,  15,
       24,  25,  26,  27,  28,  29,  30,  31,
       40,  41,  42,  43,  44,  45,  46,  47,
       56,  57,  58,  59,  60,  61,  62,  63,
       72,  73,  74,  75,  76,  77,  78,  79,
       88,  89,  90,  91,  92,  93,  94,  95,
      104, 105, 106, 107, 108, 109, 110, 111,
      120, 121, 122, 123, 124, 125, 126, 127
    },
    { /* exclusive */
        9,  10,  11,  12,  13,  14,  15,
       25,  26,  27,  28,  29,  30,  31,
       41,  42,  43,  44,  45,  46,  47,
       57,  58,  59,  60,  61,  62,  63,
       73,  74,  75,  76,  77,  78,  79,
       89,  90,  91,  92,  93,  94,  95,
      105, 106, 107, 108, 109, 110, 111
    },
    { /* shared */
      {   8, {1} },
      {  24, {1} },
      {  40, {1} },
      {  56, {1} },
      {  72, {1} },
      {  88, {1} },
      { 104, {1} },
      { 120, {1, 2, 3} },
      { 121, {2} },
      { 122, {2} },
      { 123, {2} },
      { 124, {2} },
      { 125, {2} },
      { 126, {2} },
      { 127, {2} }
    },
    { /* ghost */
      {   7, 1 },
      {  23, 1 },
      {  39, 1 },
      {  55, 1 },
      {  71, 1 },
      {  87, 1 },
      { 103, 1 },
      { 119, 1 },
      { 135, 3 },
      { 136, 2 },
      { 137, 2 },
      { 138, 2 },
      { 139, 2 },
      { 140, 2 },
      { 141, 2 },
      { 142, 2 },
      { 143, 2 }
    }
  },
  { /* color 1 */
    { /* all */
        0,   1,   2,   3,   4,   5,   6,   7,   8,
       16,  17,  18,  19,  20,  21,  22,  23,  24,
       32,  33,  34,  35,  36,  37,  38,  39,  40,
       48,  49,  50,  51,  52,  53,  54,  55,  56,
       64,  65,  66,  67,  68,  69,  70,  71,  72,
       80,  81,  82,  83,  84,  85,  86,  87,  88,
       96,  97,  98,  99, 100, 101, 102, 103, 104,
      112, 113, 114, 115, 116, 117, 118, 119, 120,
      128, 129, 130, 131, 132, 133, 134, 135, 136
    },
    { /* owned */
        0,   1,   2,   3,   4,   5,   6,   7,
       16,  17,  18,  19,  20,  21,  22,  23,
       32,  33,  34,  35,  36,  37,  38,  39,
       48,  49,  50,  51,  52,  53,  54,  55,
       64,  65,  66,  67,  68,  69,  70,  71,
       80,  81,  82,  83,  84,  85,  86,  87,
       96,  97,  98,  99, 100, 101, 102, 103,
      112, 113, 114, 115, 116, 117, 118, 119
    },
    { /* exclusive */
        0,   1,   2,   3,   4,   5,   6,
       16,  17,  18,  19,  20,  21,  22,
       32,  33,  34,  35,  36,  37,  38,
       48,  49,  50,  51,  52,  53,  54,
       64,  65,  66,  67,  68,  69,  70,
       80,  81,  82,  83,  84,  85,  86,
       96,  97,  98,  99, 100, 101, 102
    },
    { /* shared */
      {   7, {0} },
      {  23, {0} },
      {  39, {0} },
      {  55, {0} },
      {  71, {0} },
      {  87, {0} },
      { 103, {0} },
      { 112, {3} },
      { 113, {3} },
      { 114, {3} },
      { 115, {3} },
      { 116, {3} },
      { 117, {3} },
      { 118, {3} },
      { 119, {0, 2, 3} }
    },
    { /* ghost */
      {   8, 0 },
      {  24, 0 },
      {  40, 0 },
      {  56, 0 },
      {  72, 0 },
      {  88, 0 },
      { 104, 0 },
      { 120, 0 },
      { 128, 3 },
      { 129, 3 },
      { 130, 3 },
      { 131, 3 },
      { 132, 3 },
      { 133, 3 },
      { 134, 3 },
      { 135, 3 },
      { 136, 2 }
    }
  },
  { /* color 2 */
    { /* all */
      119, 120, 121, 122, 123, 124, 125, 126, 127,
      135, 136, 137, 138, 139, 140, 141, 142, 143,
      151, 152, 153, 154, 155, 156, 157, 158, 159,
      167, 168, 169, 170, 171, 172, 173, 174, 175,
      183, 184, 185, 186, 187, 188, 189, 190, 191,
      199, 200, 201, 202, 203, 204, 205, 206, 207,
      215, 216, 217, 218, 219, 220, 221, 222, 223,
      231, 232, 233, 234, 235, 236, 237, 238, 239,
      247, 248, 249, 250, 251, 252, 253, 254, 255
    },
    { /* owned */
      136, 137, 138, 139, 140, 141, 142, 143,
      152, 153, 154, 155, 156, 157, 158, 159,
      168, 169, 170, 171, 172, 173, 174, 175,
      184, 185, 186, 187, 188, 189, 190, 191,
      200, 201, 202, 203, 204, 205, 206, 207,
      216, 217, 218, 219, 220, 221, 222, 223,
      232, 233, 234, 235, 236, 237, 238, 239,
      248, 249, 250, 251, 252, 253, 254, 255
    },
    { /* exclusive */
      153, 154, 155, 156, 157, 158, 159,
      169, 170, 171, 172, 173, 174, 175,
      185, 186, 187, 188, 189, 190, 191,
      201, 202, 203, 204, 205, 206, 207,
      217, 218, 219, 220, 221, 222, 223,
      233, 234, 235, 236, 237, 238, 239,
      249, 250, 251, 252, 253, 254, 255
    },
    { /* shared */
      { 136, {0, 1, 3} },
      { 137, {0} },
      { 138, {0} },
      { 139, {0} },
      { 140, {0} },
      { 141, {0} },
      { 142, {0} },
      { 143, {0} },
      { 152, {3} },
      { 168, {3} },
      { 184, {3} },
      { 200, {3} },
      { 216, {3} },
      { 232, {3} },
      { 248, {3} }
    },
    { /* ghost */
      { 119, 1 },
      { 120, 0 },
      { 121, 0 },
      { 122, 0 },
      { 123, 0 },
      { 124, 0 },
      { 125, 0 },
      { 126, 0 },
      { 127, 0 },
      { 135, 3 },
      { 151, 3 },
      { 167, 3 },
      { 183, 3 },
      { 199, 3 },
      { 215, 3 },
      { 231, 3 },
      { 247, 3 }
    }
  },
  { /* color 3 */
    { /* all */
      128, 129, 130, 131, 132, 133, 134, 135, 136,
      144, 145, 146, 147, 148, 149, 150, 151, 152,
      160, 161, 162, 163, 164, 165, 166, 167, 168,
      176, 177, 178, 179, 180, 181, 182, 183, 184,
      192, 193, 194, 195, 196, 197, 198, 199, 200,
      208, 209, 210, 211, 212, 213, 214, 215, 216,
      224, 225, 226, 227, 228, 229, 230, 231, 232,
      240, 241, 242, 243, 244, 245, 246, 247, 248,
      112, 113, 114, 115, 116, 117, 118, 119, 120
    },
    { /* owned */
      128, 129, 130, 131, 132, 133, 134, 135,
      144, 145, 146, 147, 148, 149, 150, 151,
      160, 161, 162, 163, 164, 165, 166, 167,
      176, 177, 178, 179, 180, 181, 182, 183,
      192, 193, 194, 195, 196, 197, 198, 199,
      208, 209, 210, 211, 212, 213, 214, 215,
      224, 225, 226, 227, 228, 229, 230, 231,
      240, 241, 242, 243, 244, 245, 246, 247
    },
    { /* exclusive */
      144, 145, 146, 147, 148, 149, 150,
      160, 161, 162, 163, 164, 165, 166,
      176, 177, 178, 179, 180, 181, 182,
      192, 193, 194, 195, 196, 197, 198,
      208, 209, 210, 211, 212, 213, 214,
      224, 225, 226, 227, 228, 229, 230,
      240, 241, 242, 243, 244, 245, 246
    },
    { /* shared */
      { 128, {1} },
      { 129, {1} },
      { 130, {1} },
      { 131, {1} },
      { 132, {1} },
      { 133, {1} },
      { 134, {1} },
      { 135, {0, 1, 2} },
      { 151, {2} },
      { 167, {2} },
      { 183, {2} },
      { 199, {2} },
      { 215, {2} },
      { 231, {2} },
      { 247, {2} }
    },
    { /* ghost */
      { 112, 1 },
      { 113, 1 },
      { 114, 1 },
      { 115, 1 },
      { 116, 1 },
      { 117, 1 },
      { 118, 1 },
      { 119, 1 },
      { 120, 0 },
      { 136, 2 },
      { 152, 2 },
      { 168, 2 },
      { 184, 2 },
      { 200, 2 },
      { 216, 2 },
      { 232, 2 },
      { 248, 2 }
    }
  }
};

inline std::vector<ftui::index_coloring> vertices = {
  { /* color 0 */
    { /* all */
        7,   8,   9,  10,  11,  12,  13,  14,  15,  16,
       24,  25,  26,  27,  28,  29,  30,  31,  32,  33,
       41,  42,  43,  44,  45,  46,  47,  48,  49,  50,
       58,  59,  60,  61,  62,  63,  64,  65,  66,  67,
       75,  76,  77,  78,  79,  80,  81,  82,  83,  84,
       92,  93,  94,  95,  96,  97,  98,  99, 100, 101,
      109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
      126, 127, 128, 129, 130, 131, 132, 133, 134, 135,
      143, 144, 145, 146, 147, 148, 149, 150, 151, 152,
      160, 161, 162, 163, 164, 165, 166, 167, 168, 169
    },
    { /* owned */
        8,   9,  10,  11,  12,  13,  14,  15,  16,
       25,  26,  27,  28,  29,  30,  31,  32,  33,
       42,  43,  44,  45,  46,  47,  48,  49,  50,
       59,  60,  61,  62,  63,  64,  65,  66,  67,
       76,  77,  78,  79,  80,  81,  82,  83,  84,
       93,  94,  95,  96,  97,  98,  99, 100, 101,
      110, 111, 112, 113, 114, 115, 116, 117, 118,
      127, 128, 129, 130, 131, 132, 133, 134, 135,
      144, 145, 146, 147, 148, 149, 150, 151, 152
    },
    { /* exclusive */
       10,  11,  12,  13,  14,  15,  16,
       27,  28,  29,  30,  31,  32,  33,
       44,  45,  46,  47,  48,  49,  50,
       61,  62,  63,  64,  65,  66,  67,
       78,  79,  80,  81,  82,  83,  84,
       95,  96,  97,  98,  99, 100, 101,
      112, 113, 114, 115, 116, 117, 118
    },
    { /* shared */
      {   8, {1} },
      {   9, {1} },
      {  25, {1} },
      {  26, {1} },
      {  42, {1} },
      {  43, {1} },
      {  59, {1} },
      {  60, {1} },
      {  76, {1} },
      {  77, {1} },
      {  93, {1} },
      {  94, {1} },
      { 110, {1} },
      { 111, {1} },
      { 127, {1, 2, 3} },
      { 128, {1, 2, 3} },
      { 129, {2} },
      { 130, {2} },
      { 131, {2} },
      { 132, {2} },
      { 133, {2} },
      { 134, {2} },
      { 135, {2} },
      { 144, {1, 2, 3} },
      { 145, {1, 2, 3} },
      { 146, {2} },
      { 147, {2} },
      { 148, {2} },
      { 149, {2} },
      { 150, {2} },
      { 151, {2} },
      { 152, {2} }
    },
    { /* ghost */
      {   7, 1 },
      {  24, 1 },
      {  41, 1 },
      {  58, 1 },
      {  75, 1 },
      {  92, 1 },
      { 109, 1 },
      { 126, 1 },
      { 143, 1 },
      { 160, 3 },
      { 161, 2 },
      { 162, 2 },
      { 163, 2 },
      { 164, 2 },
      { 165, 2 },
      { 166, 2 },
      { 167, 2 },
      { 168, 2 },
      { 169, 2 }
    }
  },
  { /* color 1 */
    { /* all */
        0,   1,   2,   3,   4,   5,   6,   7,   8,   9,
       17,  18,  19,  20,  21,  22,  23,  24,  25,  26,
       34,  35,  36,  37,  38,  39,  40,  41,  42,  43,
       51,  52,  53,  54,  55,  56,  57,  58,  59,  60,
       68,  69,  70,  71,  72,  73,  74,  75,  76,  77,
       85,  86,  87,  88,  89,  90,  91,  92,  93,  94,
      102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
      119, 120, 121, 122, 123, 124, 125, 126, 127, 128,
      136, 137, 138, 139, 140, 141, 142, 143, 144, 145,
      153, 154, 155, 156, 157, 158, 159, 160, 161, 162
    },
    { /* owned */
        0,   1,   2,   3,   4,   5,   6,   7,
       17,  18,  19,  20,  21,  22,  23,  24,
       34,  35,  36,  37,  38,  39,  40,  41,
       51,  52,  53,  54,  55,  56,  57,  58,
       68,  69,  70,  71,  72,  73,  74,  75,
       85,  86,  87,  88,  89,  90,  91,  92,
      102, 103, 104, 105, 106, 107, 108, 109,
      119, 120, 121, 122, 123, 124, 125, 126,
      136, 137, 138, 139, 140, 141, 142, 143
    },
    { /* exclusive */
        0,   1,   2,   3,   4,   5,   6,
       17,  18,  19,  20,  21,  22,  23,
       34,  35,  36,  37,  38,  39,  40,
       51,  52,  53,  54,  55,  56,  57,
       68,  69,  70,  71,  72,  73,  74,
       85,  86,  87,  88,  89,  90,  91,
      102, 103, 104, 105, 106, 107, 108
    },
    { /* shared */
      {   7, {0} },
      {  24, {0} },
      {  41, {0} },
      {  58, {0} },
      {  75, {0} },
      {  92, {0} },
      { 109, {0} },
      { 119, {3} },
      { 120, {3} },
      { 121, {3} },
      { 122, {3} },
      { 123, {3} },
      { 124, {3} },
      { 125, {3} },
      { 126, {3} },
      { 136, {3} },
      { 137, {3} },
      { 138, {3} },
      { 139, {3} },
      { 140, {3} },
      { 141, {3} },
      { 142, {3} },
      { 143, {3} }
    },
    { /* ghost */
      {   8, 0 },
      {   9, 0 },
      {  25, 0 },
      {  26, 0 },
      {  42, 0 },
      {  43, 0 },
      {  59, 0 },
      {  60, 0 },
      {  76, 0 },
      {  77, 0 },
      {  93, 0 },
      {  94, 0 },
      { 110, 0 },
      { 111, 0 },
      { 127, 0 },
      { 128, 0 },
      { 144, 0 },
      { 145, 0 },
      { 153, 3 },
      { 154, 3 },
      { 155, 3 },
      { 156, 3 },
      { 157, 3 },
      { 158, 3 },
      { 159, 3 },
      { 160, 3 },
      { 161, 2 },
      { 162, 2 }
    }
  },
  { /* color 2 */
    { /* all */
      126, 127, 128, 129, 130, 131, 132, 133, 134, 135,
      143, 144, 145, 146, 147, 148, 149, 150, 151, 152,
      160, 161, 162, 163, 164, 165, 166, 167, 168, 169,
      177, 178, 179, 180, 181, 182, 183, 184, 185, 186,
      194, 195, 196, 197, 198, 199, 200, 201, 202, 203,
      211, 212, 213, 214, 215, 216, 217, 218, 219, 220,
      228, 229, 230, 231, 232, 233, 234, 235, 236, 237,
      245, 246, 247, 248, 249, 250, 251, 252, 253, 254,
      262, 263, 264, 265, 266, 267, 268, 269, 270, 271,
      279, 280, 281, 282, 283, 284, 285, 286, 287, 288
    },
    { /* owned */
      161, 162, 163, 164, 165, 166, 167, 168, 169,
      178, 179, 180, 181, 182, 183, 184, 185, 186,
      195, 196, 197, 198, 199, 200, 201, 202, 203,
      212, 213, 214, 215, 216, 217, 218, 219, 220,
      229, 230, 231, 232, 233, 234, 235, 236, 237,
      246, 247, 248, 249, 250, 251, 252, 253, 254,
      263, 264, 265, 266, 267, 268, 269, 270, 271,
      280, 281, 282, 283, 284, 285, 286, 287, 288
    },
    { /* exclusive */
      180, 181, 182, 183, 184, 185, 186,
      197, 198, 199, 200, 201, 202, 203,
      214, 215, 216, 217, 218, 219, 220,
      231, 232, 233, 234, 235, 236, 237,
      248, 249, 250, 251, 252, 253, 254,
      265, 266, 267, 268, 269, 270, 271,
      282, 283, 284, 285, 286, 287, 288
    },
    { /* shared */
      { 161, {0, 1, 3} },
      { 162, {0, 1, 3} },
      { 163, {0} },
      { 164, {0} },
      { 165, {0} },
      { 166, {0} },
      { 167, {0} },
      { 168, {0} },
      { 169, {0} },
      { 178, {3} },
      { 179, {3} },
      { 195, {3} },
      { 196, {3} },
      { 212, {3} },
      { 213, {3} },
      { 229, {3} },
      { 230, {3} },
      { 246, {3} },
      { 247, {3} },
      { 263, {3} },
      { 264, {3} },
      { 280, {3} },
      { 281, {3} }
    },
    { /* ghost */
      { 126, 1 },
      { 127, 0 },
      { 128, 0 },
      { 129, 0 },
      { 130, 0 },
      { 131, 0 },
      { 132, 0 },
      { 133, 0 },
      { 134, 0 },
      { 135, 0 },
      { 143, 1 },
      { 144, 0 },
      { 145, 0 },
      { 146, 0 },
      { 147, 0 },
      { 148, 0 },
      { 149, 0 },
      { 150, 0 },
      { 151, 0 },
      { 152, 0 },
      { 160, 3 },
      { 177, 3 },
      { 194, 3 },
      { 211, 3 },
      { 228, 3 },
      { 245, 3 },
      { 262, 3 },
      { 279, 3 }
    }
  },
  { /* color 3 */
    { /* all */
      119, 120, 121, 122, 123, 124, 125, 126, 127, 128,
      136, 137, 138, 139, 140, 141, 142, 143, 144, 145,
      153, 154, 155, 156, 157, 158, 159, 160, 161, 162,
      170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
      187, 188, 189, 190, 191, 192, 193, 194, 195, 196,
      204, 205, 206, 207, 208, 209, 210, 211, 212, 213,
      221, 222, 223, 224, 225, 226, 227, 228, 229, 230,
      238, 239, 240, 241, 242, 243, 244, 245, 246, 247,
      255, 256, 257, 258, 259, 260, 261, 262, 263, 264,
      272, 273, 274, 275, 276, 277, 278, 279, 280, 281
    },
    { /* owned */
      153, 154, 155, 156, 157, 158, 159, 160,
      170, 171, 172, 173, 174, 175, 176, 177,
      187, 188, 189, 190, 191, 192, 193, 194,
      204, 205, 206, 207, 208, 209, 210, 211,
      221, 222, 223, 224, 225, 226, 227, 228,
      238, 239, 240, 241, 242, 243, 244, 245,
      255, 256, 257, 258, 259, 260, 261, 262,
      272, 273, 274, 275, 276, 277, 278, 279
    },
    { /* exclusive */
      170, 171, 172, 173, 174, 175, 176,
      187, 188, 189, 190, 191, 192, 193,
      204, 205, 206, 207, 208, 209, 210,
      221, 222, 223, 224, 225, 226, 227,
      238, 239, 240, 241, 242, 243, 244,
      255, 256, 257, 258, 259, 260, 261,
      272, 273, 274, 275, 276, 277, 278
    },
    { /* shared */
      { 153, {1} },
      { 154, {1} },
      { 155, {1} },
      { 156, {1} },
      { 157, {1} },
      { 158, {1} },
      { 159, {1} },
      { 160, {1} },
      { 177, {2} },
      { 194, {2} },
      { 211, {2} },
      { 228, {2} },
      { 245, {2} },
      { 262, {2} },
      { 279, {2} }
    },
    { /* ghost */
      { 119, 1 },
      { 120, 1 },
      { 121, 1 },
      { 122, 1 },
      { 123, 1 },
      { 124, 1 },
      { 125, 1 },
      { 126, 1 },
      { 127, 0 },
      { 128, 0 },
      { 136, 1 },
      { 137, 1 },
      { 138, 1 },
      { 139, 1 },
      { 140, 1 },
      { 141, 1 },
      { 142, 1 },
      { 143, 1 },
      { 144, 0 },
      { 145, 0 },
      { 161, 2 },
      { 162, 2 },
      { 178, 2 },
      { 179, 2 },
      { 195, 2 },
      { 196, 2 },
      { 212, 2 },
      { 213, 2 },
      { 229, 2 },
      { 230, 2 },
      { 246, 2 },
      { 247, 2 },
      { 263, 2 },
      { 264, 2 },
      { 280, 2 },
      { 281, 2 }
    }
  }
};

std::vector<std::vector<ftui::index_coloring>> idx_colorings = {
  {/* color 0 */
    cells[0],
    vertices[0]
  },
  {/* color 1 */
    cells[1],
    vertices[1]
  },
  {/* color 2 */
    cells[2],
    vertices[2]
  },
  {/* color 3 */
    cells[3],
    vertices[3]
  }
};

std::vector<std::vector<std::vector<std::size_t>>> cnx_allocs = {
  {/* color 0 */
    {connectivity[0][0].indices.size(), },
    {connectivity[0][0].indices.size(), }
  },
  {/* color 1 */
    {connectivity[1][0].indices.size()},
    {connectivity[1][0].indices.size()}
  },
  {/* color 2 */
    {connectivity[2][0].indices.size()},
    {connectivity[2][0].indices.size()}
  },
  {/* color 3 */
    {connectivity[3][0].indices.size()},
    {connectivity[3][0].indices.size()}
  }
};

std::vector<std::vector<std::vector<ftui::crs>>> cnx_colorings = {
  {/* color 0 */
    connectivity[0]
  },
  {/* color 1 */
    connectivity[1]
  },
  {/* color 2 */
    connectivity[2]
  },
  {/* color 3 */
    connectivity[3]
  }
};
// clang-format on

} // namespace fixed

#if 0
inline std::vector<flu::index_coloring> cells = {
  {
      7,   8,   9,  10,  11,  12,  13,  14,  15,
     23,  24,  25,  26,  27,  28,  29,  30,  31,
     39,  40,  41,  42,  43,  44,  45,  46,  47,
     55,  56,  57,  58,  59,  60,  61,  62,  63,
     71,  72,  73,  74,  75,  76,  77,  78,  79,
     87,  88,  89,  90,  91,  92,  93,  94,  95,
    103, 104, 105, 106, 107, 108, 109, 110, 111,
    119, 120, 121, 122, 123, 124, 125, 126, 127,
    135, 136, 137, 138, 139, 140, 141, 142, 143
  },
  {
      0,   1,   2,   3,   4,   5,   6,   7,   8,
     16,  17,  18,  19,  20,  21,  22,  23,  24,
     32,  33,  34,  35,  36,  37,  38,  39,  40,
     48,  49,  50,  51,  52,  53,  54,  55,  56,
     64,  65,  66,  67,  68,  69,  70,  71,  72,
     80,  81,  82,  83,  84,  85,  86,  87,  88,
     96,  97,  98,  99, 100, 101, 102, 103, 104,
    112, 113, 114, 115, 116, 117, 118, 119, 120,
    128, 129, 130, 131, 132, 133, 134, 135, 136
  },
  {
    119, 120, 121, 122, 123, 124, 125, 126, 127,
    135, 136, 137, 138, 139, 140, 141, 142, 143,
    151, 152, 153, 154, 155, 156, 157, 158, 159,
    167, 168, 169, 170, 171, 172, 173, 174, 175,
    183, 184, 185, 186, 187, 188, 189, 190, 191,
    199, 200, 201, 202, 203, 204, 205, 206, 207,
    215, 216, 217, 218, 219, 220, 221, 222, 223,
    231, 232, 233, 234, 235, 236, 237, 238, 239,
    247, 248, 249, 250, 251, 252, 253, 254, 255
  },
  {
    112, 113, 114, 115, 116, 117, 118, 119, 120,
    128, 129, 130, 131, 132, 133, 134, 135, 136
    144, 145, 146, 147, 148, 149, 150, 151, 152,
    160, 161, 162, 163, 164, 165, 166, 167, 168,
    176, 177, 178, 179, 180, 181, 182, 183, 184,
    192, 193, 194, 195, 196, 197, 198, 199, 200
    208, 209, 210, 211, 212, 213, 214, 215, 216,
    224, 225, 226, 227, 228, 229, 230, 231, 232,
    240, 241, 242, 243, 244, 245, 246, 247, 248
  }
};

inline std::vector<flu::index_coloring> vertices = {
  {
      7,   8,   9,  10,  11,  12,  13,  14,  15,  16,
     24,  25,  26,  27,  28,  29,  30,  31,  32,  33,
     41,  42,  43,  44,  45,  46,  47,  48,  49,  50,
     58,  59,  60,  61,  62,  63,  64,  65,  66,  67,
     75,  76,  77,  78,  79,  80,  81,  82,  83,  84,
     92,  93,  94,  95,  96,  97,  98,  99, 100, 101,
    109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
    126, 127, 128, 129, 130, 131, 132, 133, 134, 135,
    143, 144, 145, 146, 147, 148, 149, 150, 151, 152,
    160, 161, 162, 163, 164, 165, 166, 167, 168, 169 
  },
  {
      0,   1,   2,   3,   4,   5,   6,   7,   8,   9,
     17,  18,  19,  20,  21,  22,  23,  24,  25,  26,
     34,  35,  36,  37,  38,  39,  40,  41,  42,  43,
     51,  52,  53,  54,  55,  56,  57,  58,  59,  60,
     68,  69,  70,  71,  72,  73,  74,  75,  76,  77,
     85,  86,  87,  88,  89,  90,  91,  92,  93,  94,
    102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
    119, 120, 121, 122, 123, 124, 125, 126, 127, 128,
    136, 137, 138, 139, 140, 141, 142, 143, 144, 145,
    153, 154, 155, 156, 157, 158, 159, 160, 161, 162
  },
  {
    126, 127, 128, 129, 130, 131, 132, 133, 134, 135,
    143, 144, 145, 146, 147, 148, 149, 150, 151, 152,
    160, 161, 162, 163, 164, 165, 166, 167, 168, 169,
    177, 178, 179, 180, 181, 182, 183, 184, 185, 186,
    194, 195, 196, 197, 198, 199, 200, 201, 202, 203,
    211, 212, 213, 214, 215, 216, 217, 218, 219, 220,
    228, 229, 230, 231, 232, 233, 234, 235, 236, 237,
    245, 246, 247, 248, 249, 250, 251, 252, 253, 254,
    262, 263, 264, 265, 266, 267, 268, 269, 270, 271,
    279, 280, 281, 282, 283, 284, 285, 286, 287, 288
  },
  {
    119, 120, 121, 122, 123, 124, 125, 126, 127, 128,
    136, 137, 138, 139, 140, 141, 142, 143, 144, 145,
    153, 154, 155, 156, 157, 158, 159, 160, 161, 162,
    170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
    187, 188, 189, 190, 191, 192, 193, 194, 195, 196,
    204, 205, 206, 207, 208, 209, 210, 211, 212, 213,
    221, 222, 223, 224, 225, 226, 227, 228, 229, 230,
    238, 239, 240, 241, 242, 243, 244, 245, 246, 247,
    255, 256, 257, 258, 259, 260, 261, 262, 263, 264,
    272, 273, 274, 275, 276, 277, 278, 279, 280, 281
  }
};
#endif
