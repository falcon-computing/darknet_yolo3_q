#define OVERLAP            2
#define COMPUTE_UNIT       1
#define TILING_IMAGE       16
#define PARALLEL_FILTER    16
#define ORG_DATA_WIDTH     8
#define WIDE_BUS_WIDTH     512
#define SPLITING_FACTOR    13
#define INPUT_LAYER_NUM    107
#define OUTPUT_LAYER_NUM   75
#define R_MULT             32
#define FACTORS            4
const float quant_multipler[75][2]=   
{
	{ R_MULT / (4   * 15.497), 12.537}, { R_MULT / (256  * 12.537), 40.000}, { R_MULT / (64  * 40.000), 40.000}, { R_MULT / (128  * 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000},//0~4 
	{ R_MULT / (256 * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000}, { R_MULT / (128 * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000}, { R_MULT / (1024 * 40.000), 40.000},//5~14
	{ R_MULT / (256 * 40.000), 40.000}, { R_MULT / (2048 * 40.000), 40.000}, { R_MULT / (128 * 40.000), 40.000}, { R_MULT / (1024 * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000},//10~14
	{ R_MULT / (512 * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000}, { R_MULT / (512 * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000},//15~19
	{ R_MULT / (256 * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000}, { R_MULT / (256 * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000},//20~24
	{ R_MULT / (256 * 40.000), 40.000}, { R_MULT / (2048 * 40.000), 40.000}, { R_MULT / (256 * 40.000), 40.000}, { R_MULT / (4096 * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000},//25~29
	{ R_MULT / (1024* 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000}, { R_MULT / (512 * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000},//30~34
	{ R_MULT / (256 * 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000}, { R_MULT / (512 * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000},//35~39
	{ R_MULT / (512 * 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000}, { R_MULT / (256 * 40.000), 40.000}, { R_MULT / (2048 * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000},//40~44
	{ R_MULT / (2048* 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000}, { R_MULT / (512 * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000},//45~49
	{ R_MULT / (512 * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000}, { R_MULT / (512 * 40.000), 40.000}, { R_MULT / (1024 * 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000},//50~54
	{ R_MULT / (1024* 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000}, { R_MULT / (512 * 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000},//55~59
	{ R_MULT / (512 * 40.000), 40.000}, { R_MULT / (1024 * 40.000), 40.000}, { R_MULT / (256 * 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000},//60~64
	{ R_MULT / (512 * 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000}, { R_MULT / (128 * 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000},//65~69
	{ R_MULT / (128 * 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000}, { R_MULT / (128 * 40.000), 40.000}, { R_MULT / (512  * 40.000), 40.000}, { R_MULT / (256  * 40.000), 40.000}//70~74
};
const int config_list_all[75][3][32] = {
	{ //layer000 => layer000
		{3,416,416,16,1,416,416,32,416,1,1,0,417,0,1,0,173056,2768896,173056,5537792,13,32,36,13,1560,416,5408,32,0,43264,0,1228800},
		{0,416,416,32,0,416,416,32,416,0,0,0,0,0,0,0,173056,2768896,173056,5537792,13,32,0,0,1352,64,0,32,0,43264,0,1228800},
		{0,416,416,32,0,416,416,32,416,0,0,0,0,0,0,0,173056,2768896,173056,5537792,13,32,0,0,1352,64,0,32,0,43264,0,1228800}
	},
	{ //layer001 => layer001
		{3,416,416,32,1,208,208,64,208,2,1,0,208,0,1,0,173056,5537792,43264,2768896,13,29,72,10,1560,208,5408,30,43264,129792,72,1229056},
		{0,208,208,64,0,208,208,64,208,0,0,0,0,0,0,0,173056,5537792,43264,2768896,26,29,0,0,1352,32,0,30,43264,129792,72,1229056},
		{0,208,208,64,0,208,208,64,208,0,0,0,0,0,0,0,173056,5537792,43264,2768896,26,29,0,0,1352,32,0,30,43264,129792,72,1229056}
	},
	{ //layer002 => layer002
		{1,208,208,64,1,208,208,32,208,1,0,0,208,0,1,0,43264,2768896,43264,1384448,26,8,16,26,1352,208,5408,8,129792,173056,360,1229312},
		{0,208,208,32,0,208,208,32,208,0,0,0,0,0,0,0,43264,2768896,43264,1384448,26,8,0,0,1352,16,0,8,129792,173056,360,1229312},
		{0,208,208,32,0,208,208,32,208,0,0,0,0,0,0,0,43264,2768896,43264,1384448,26,8,0,0,1352,16,0,8,129792,173056,360,1229312}
	},
	{ //layer003 => layer003 layer004
		{3,208,208,32,1,208,208,64,208,1,1,0,209,0,1,0,43264,1384448,43264,2768896,26,8,72,26,1456,208,5408,8,173056,194688,392,1229568},
		{1,208,208,64,0,208,208,64,208,0,0,0,0,0,0,0,43264,2768896,43264,2768896,0,0,0,0,2704,64,0,-206,129792,194688,0,0},
		{0,208,208,64,0,208,208,64,208,0,0,0,0,0,0,0,43264,2768896,43264,2768896,26,0,0,0,1352,32,0,-206,129792,194688,0,0}
	},
	{ //layer004 => layer005
		{3,208,208,64,1,104,104,128,104,2,1,0,104,0,1,0,43264,2768896,10816,1384448,27,7,144,12,1508,104,5616,8,194688,237952,680,1229824},
		{0,104,104,128,0,104,104,128,104,0,0,0,0,0,0,0,43264,2768896,10816,1384448,52,7,0,0,1352,16,0,8,194688,237952,680,1229824},
		{0,104,104,128,0,104,104,128,104,0,0,0,0,0,0,0,43264,2768896,10816,1384448,52,7,0,0,1352,16,0,8,194688,237952,680,1229824}
	},
	{ //layer005 => layer006
		{1,104,104,128,1,104,104,64,104,1,0,0,104,0,1,0,10816,1384448,10816,692224,52,2,32,52,1352,104,5408,2,237952,259584,1832,1230080},
		{0,104,104,64,0,104,104,64,104,0,0,0,0,0,0,0,10816,1384448,10816,692224,52,2,0,0,1352,8,0,2,237952,259584,1832,1230080},
		{0,104,104,64,0,104,104,64,104,0,0,0,0,0,0,0,10816,1384448,10816,692224,52,2,0,0,1352,8,0,2,237952,259584,1832,1230080}
	},
	{ //layer006 => layer007 layer008
		{3,104,104,64,1,104,104,128,104,1,1,0,105,0,1,0,10816,692224,10816,1384448,52,2,144,52,1404,104,5408,2,259584,270400,1960,1230336},
		{1,104,104,128,0,104,104,128,104,0,0,0,0,0,0,0,10816,1384448,10816,1384448,0,0,0,0,2704,32,0,-102,237952,270400,0,0},
		{0,104,104,128,0,104,104,128,104,0,0,0,0,0,0,0,10816,1384448,10816,1384448,52,0,0,0,1352,16,0,-102,237952,270400,0,0}
	},
	{ //layer007 => layer009
		{1,104,104,128,1,104,104,64,104,1,0,0,104,0,1,0,10816,1384448,10816,692224,52,2,32,52,1352,104,5408,2,270400,292032,3112,1230592},
		{0,104,104,64,0,104,104,64,104,0,0,0,0,0,0,0,10816,1384448,10816,692224,52,2,0,0,1352,8,0,2,270400,292032,3112,1230592},
		{0,104,104,64,0,104,104,64,104,0,0,0,0,0,0,0,10816,1384448,10816,692224,52,2,0,0,1352,8,0,2,270400,292032,3112,1230592}
	},
	{ //layer008 => layer010 layer011
		{3,104,104,64,1,104,104,128,104,1,1,0,105,0,1,0,10816,692224,10816,1384448,52,2,144,52,1404,104,5408,2,292032,302848,3240,1230848},
		{1,104,104,128,0,104,104,128,104,0,0,0,0,0,0,0,10816,1384448,10816,1384448,0,0,0,0,2704,32,0,-102,270400,302848,0,0},
		{0,104,104,128,0,104,104,128,104,0,0,0,0,0,0,0,10816,1384448,10816,1384448,52,0,0,0,1352,16,0,-102,270400,302848,0,0}
	},
	{ //layer009 => layer012
		{3,104,104,128,1,52,52,256,52,2,1,0,52,0,1,0,10816,1384448,2704,692224,57,1,288,46,1534,52,5928,2,302848,324480,4392,1231104},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,10816,1384448,2704,692224,104,1,0,0,1352,8,0,2,302848,324480,4392,1231104},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,10816,1384448,2704,692224,104,1,0,0,1352,8,0,2,302848,324480,4392,1231104}
	},
	{ //layer010 => layer013
		{1,52,52,256,1,52,52,128,52,1,0,0,52,0,1,0,2704,692224,2704,346112,52,1,64,52,1352,52,2704,1,324480,335296,9000,1231360},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,324480,335296,9000,1231360},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,324480,335296,9000,1231360}
	},
	{ //layer011 => layer014 layer015
		{3,52,52,128,1,52,52,256,52,1,1,0,53,0,1,0,2704,346112,2704,692224,52,1,288,52,1352,52,2704,1,335296,340704,9512,1231616},
		{1,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,0,0,0,0,2704,16,0,-50,324480,340704,0,0},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,104,0,0,0,1352,8,0,-50,324480,340704,0,0}
	},
	{ //layer012 => layer016
		{1,52,52,256,1,52,52,128,52,1,0,0,52,0,1,0,2704,692224,2704,346112,52,1,64,52,1352,52,2704,1,340704,351520,14120,1231872},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,340704,351520,14120,1231872},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,340704,351520,14120,1231872}
	},
	{ //layer013 => layer017 layer018
		{3,52,52,128,1,52,52,256,52,1,1,0,53,0,1,0,2704,346112,2704,692224,52,1,288,52,1352,52,2704,1,351520,356928,14632,1232128},
		{1,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,0,0,0,0,2704,16,0,-50,340704,356928,0,0},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,104,0,0,0,1352,8,0,-50,340704,356928,0,0}
	},
	{ //layer014 => layer019
		{1,52,52,256,1,52,52,128,52,1,0,0,52,0,1,0,2704,692224,2704,346112,52,1,64,52,1352,52,2704,1,356928,367744,19240,1232384},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,356928,367744,19240,1232384},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,356928,367744,19240,1232384}
	},
	{ //layer015 => layer020 layer021
		{3,52,52,128,1,52,52,256,52,1,1,0,53,0,1,0,2704,346112,2704,692224,52,1,288,52,1352,52,2704,1,367744,373152,19752,1232640},
		{1,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,0,0,0,0,2704,16,0,-50,356928,373152,0,0},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,104,0,0,0,1352,8,0,-50,356928,373152,0,0}
	},
	{ //layer016 => layer022
		{1,52,52,256,1,52,52,128,52,1,0,0,52,0,1,0,2704,692224,2704,346112,52,1,64,52,1352,52,2704,1,373152,383968,24360,1232896},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,373152,383968,24360,1232896},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,373152,383968,24360,1232896}
	},
	{ //layer017 => layer023 layer024
		{3,52,52,128,1,52,52,256,52,1,1,0,53,0,1,0,2704,346112,2704,692224,52,1,288,52,1352,52,2704,1,383968,389376,24872,1233152},
		{1,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,0,0,0,0,2704,16,0,-50,373152,389376,0,0},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,104,0,0,0,1352,8,0,-50,373152,389376,0,0}
	},
	{ //layer018 => layer025
		{1,52,52,256,1,52,52,128,52,1,0,0,52,0,1,0,2704,692224,2704,346112,52,1,64,52,1352,52,2704,1,389376,400192,29480,1233408},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,389376,400192,29480,1233408},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,389376,400192,29480,1233408}
	},
	{ //layer019 => layer026 layer027
		{3,52,52,128,1,52,52,256,52,1,1,0,53,0,1,0,2704,346112,2704,692224,52,1,288,52,1352,52,2704,1,400192,405600,29992,1233664},
		{1,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,0,0,0,0,2704,16,0,-50,389376,405600,0,0},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,104,0,0,0,1352,8,0,-50,389376,405600,0,0}
	},
	{ //layer020 => layer028
		{1,52,52,256,1,52,52,128,52,1,0,0,52,0,1,0,2704,692224,2704,346112,52,1,64,52,1352,52,2704,1,405600,416416,34600,1233920},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,405600,416416,34600,1233920},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,405600,416416,34600,1233920}
	},
	{ //layer021 => layer029 layer030
		{3,52,52,128,1,52,52,256,52,1,1,0,53,0,1,0,2704,346112,2704,692224,52,1,288,52,1352,52,2704,1,416416,421824,35112,1234176},
		{1,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,0,0,0,0,2704,16,0,-50,405600,421824,0,0},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,104,0,0,0,1352,8,0,-50,405600,421824,0,0}
	},
	{ //layer022 => layer031
		{1,52,52,256,1,52,52,128,52,1,0,0,52,0,1,0,2704,692224,2704,346112,52,1,64,52,1352,52,2704,1,421824,432640,39720,1234432},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,421824,432640,39720,1234432},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,421824,432640,39720,1234432}
	},
	{ //layer023 => layer032 layer033
		{3,52,52,128,1,52,52,256,52,1,1,0,53,0,1,0,2704,346112,2704,692224,52,1,288,52,1352,52,2704,1,432640,438048,40232,1234688},
		{1,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,0,0,0,0,2704,16,0,-50,421824,438048,0,0},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,104,0,0,0,1352,8,0,-50,421824,438048,0,0}
	},
	{ //layer024 => layer034
		{1,52,52,256,1,52,52,128,52,1,0,0,52,0,1,0,2704,692224,2704,346112,52,1,64,52,1352,52,2704,1,438048,448864,44840,1234944},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,438048,448864,44840,1234944},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,438048,448864,44840,1234944}
	},
	{ //layer025 => layer035 layer036
		{3,52,52,128,1,52,52,256,52,1,1,0,53,0,1,0,2704,346112,2704,692224,52,1,288,52,1352,52,2704,1,448864,454272,45352,1235200},
		{1,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,0,0,0,0,2704,16,0,-50,438048,624000,0,0},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,104,0,0,0,1352,8,0,-50,438048,624000,0,0}
	},
	{ //layer026 => layer037
		{3,52,52,256,1,26,26,512,28,2,1,0,26,0,1,0,2704,692224,676,346112,52,0,576,52,1352,26,2704,1,624000,465088,49960,1235456},
		{0,26,26,512,0,26,26,512,28,0,0,0,0,0,0,0,2704,692224,676,346112,208,0,0,0,1456,4,2,1,624000,465088,49960,1235456},
		{0,26,26,512,0,26,26,512,28,0,0,0,0,0,0,0,2704,692224,676,346112,208,0,0,0,1456,4,2,1,624000,465088,49960,1235456}
	},
	{ //layer027 => layer038
		{1,28,26,512,1,28,26,256,28,1,0,0,28,0,1,0,728,372736,728,186368,26,1,128,26,728,28,728,1,465088,470912,68392,1235712},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,465088,470912,68392,1235712},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,465088,470912,68392,1235712}
	},
	{ //layer028 => layer039 layer040
		{3,28,26,256,1,28,26,512,28,1,1,0,29,0,1,0,728,186368,728,372736,26,1,576,26,728,28,728,1,470912,473824,70440,1235968},
		{1,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,0,0,0,0,2912,8,0,-24,465088,473824,0,0},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,208,0,0,0,1456,4,2,-24,465088,473824,0,0}
	},
	{ //layer029 => layer041
		{1,28,26,512,1,28,26,256,28,1,0,0,28,0,1,0,728,372736,728,186368,26,1,128,26,728,28,728,1,473824,479648,88872,1236224},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,473824,479648,88872,1236224},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,473824,479648,88872,1236224}
	},
	{ //layer030 => layer042 layer043
		{3,28,26,256,1,28,26,512,28,1,1,0,29,0,1,0,728,186368,728,372736,26,1,576,26,728,28,728,1,479648,482560,90920,1236480},
		{1,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,0,0,0,0,2912,8,0,-24,473824,482560,0,0},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,208,0,0,0,1456,4,2,-24,473824,482560,0,0}
	},
	{ //layer031 => layer044
		{1,28,26,512,1,28,26,256,28,1,0,0,28,0,1,0,728,372736,728,186368,26,1,128,26,728,28,728,1,482560,488384,109352,1236736},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,482560,488384,109352,1236736},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,482560,488384,109352,1236736}
	},
	{ //layer032 => layer045 layer046
		{3,28,26,256,1,28,26,512,28,1,1,0,29,0,1,0,728,186368,728,372736,26,1,576,26,728,28,728,1,488384,491296,111400,1236992},
		{1,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,0,0,0,0,2912,8,0,-24,482560,491296,0,0},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,208,0,0,0,1456,4,2,-24,482560,491296,0,0}
	},
	{ //layer033 => layer047
		{1,28,26,512,1,28,26,256,28,1,0,0,28,0,1,0,728,372736,728,186368,26,1,128,26,728,28,728,1,491296,497120,129832,1237248},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,491296,497120,129832,1237248},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,491296,497120,129832,1237248}
	},
	{ //layer034 => layer048 layer049
		{3,28,26,256,1,28,26,512,28,1,1,0,29,0,1,0,728,186368,728,372736,26,1,576,26,728,28,728,1,497120,500032,131880,1237504},
		{1,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,0,0,0,0,2912,8,0,-24,491296,500032,0,0},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,208,0,0,0,1456,4,2,-24,491296,500032,0,0}
	},
	{ //layer035 => layer050
		{1,28,26,512,1,28,26,256,28,1,0,0,28,0,1,0,728,372736,728,186368,26,1,128,26,728,28,728,1,500032,505856,150312,1237760},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,500032,505856,150312,1237760},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,500032,505856,150312,1237760}
	},
	{ //layer036 => layer051 layer052
		{3,28,26,256,1,28,26,512,28,1,1,0,29,0,1,0,728,186368,728,372736,26,1,576,26,728,28,728,1,505856,508768,152360,1238016},
		{1,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,0,0,0,0,2912,8,0,-24,500032,508768,0,0},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,208,0,0,0,1456,4,2,-24,500032,508768,0,0}
	},
	{ //layer037 => layer053
		{1,28,26,512,1,28,26,256,28,1,0,0,28,0,1,0,728,372736,728,186368,26,1,128,26,728,28,728,1,508768,514592,170792,1238272},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,508768,514592,170792,1238272},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,508768,514592,170792,1238272}
	},
	{ //layer038 => layer054 layer055
		{3,28,26,256,1,28,26,512,28,1,1,0,29,0,1,0,728,186368,728,372736,26,1,576,26,728,28,728,1,514592,517504,172840,1238528},
		{1,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,0,0,0,0,2912,8,0,-24,508768,517504,0,0},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,208,0,0,0,1456,4,2,-24,508768,517504,0,0}
	},
	{ //layer039 => layer056
		{1,28,26,512,1,28,26,256,28,1,0,0,28,0,1,0,728,372736,728,186368,26,1,128,26,728,28,728,1,517504,523328,191272,1238784},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,517504,523328,191272,1238784},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,517504,523328,191272,1238784}
	},
	{ //layer040 => layer057 layer058
		{3,28,26,256,1,28,26,512,28,1,1,0,29,0,1,0,728,186368,728,372736,26,1,576,26,728,28,728,1,523328,526240,193320,1239040},
		{1,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,0,0,0,0,2912,8,0,-24,517504,526240,0,0},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,208,0,0,0,1456,4,2,-24,517504,526240,0,0}
	},
	{ //layer041 => layer059
		{1,28,26,512,1,28,26,256,28,1,0,0,28,0,1,0,728,372736,728,186368,26,1,128,26,728,28,728,1,526240,532064,211752,1239296},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,526240,532064,211752,1239296},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,526240,532064,211752,1239296}
	},
	{ //layer042 => layer060 layer061
		{3,28,26,256,1,28,26,512,28,1,1,0,29,0,1,0,728,186368,728,372736,26,1,576,26,728,28,728,1,532064,534976,213800,1239552},
		{1,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,0,0,0,0,2912,8,0,-24,526240,583648,0,0},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,372736,728,372736,208,0,0,0,1456,4,2,-24,526240,583648,0,0}
	},
	{ //layer043 => layer062
		{3,28,26,512,1,14,13,1024,16,2,1,0,14,0,1,0,728,372736,182,186368,26,0,1152,26,728,14,728,1,583648,540800,232232,1239808},
		{0,14,13,1024,0,14,13,1024,16,0,0,0,0,0,0,0,728,372736,182,186368,208,0,0,0,832,4,1,1,583648,540800,232232,1239808},
		{0,14,13,1024,0,14,13,1024,16,0,0,0,0,0,0,0,728,372736,182,186368,208,0,0,0,832,4,1,1,583648,540800,232232,1239808}
	},
	{ //layer044 => layer063
		{1,16,13,1024,1,16,13,512,16,1,0,0,16,0,1,0,208,212992,208,106496,13,1,256,13,416,16,208,1,540800,544128,305960,1240064},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,540800,544128,305960,1240064},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,540800,544128,305960,1240064}
	},
	{ //layer045 => layer064 layer065
		{3,16,13,512,1,16,13,1024,16,1,1,0,17,0,1,0,208,106496,208,212992,13,1,1152,13,416,16,208,1,544128,545792,314152,1240320},
		{1,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,212992,208,212992,0,0,0,0,3328,4,0,-11,540800,545792,0,0},
		{0,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,212992,208,212992,208,0,0,0,832,4,1,-11,540800,545792,0,0}
	},
	{ //layer046 => layer066
		{1,16,13,1024,1,16,13,512,16,1,0,0,16,0,1,0,208,212992,208,106496,13,1,256,13,416,16,208,1,545792,549120,387880,1240576},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,545792,549120,387880,1240576},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,545792,549120,387880,1240576}
	},
	{ //layer047 => layer067 layer068
		{3,16,13,512,1,16,13,1024,16,1,1,0,17,0,1,0,208,106496,208,212992,13,1,1152,13,416,16,208,1,549120,550784,396072,1240832},
		{1,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,212992,208,212992,0,0,0,0,3328,4,0,-11,545792,550784,0,0},
		{0,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,212992,208,212992,208,0,0,0,832,4,1,-11,545792,550784,0,0}
	},
	{ //layer048 => layer069
		{1,16,13,1024,1,16,13,512,16,1,0,0,16,0,1,0,208,212992,208,106496,13,1,256,13,416,16,208,1,550784,554112,469800,1241088},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,550784,554112,469800,1241088},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,550784,554112,469800,1241088}
	},
	{ //layer049 => layer070 layer071
		{3,16,13,512,1,16,13,1024,16,1,1,0,17,0,1,0,208,106496,208,212992,13,1,1152,13,416,16,208,1,554112,555776,477992,1241344},
		{1,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,212992,208,212992,0,0,0,0,3328,4,0,-11,550784,555776,0,0},
		{0,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,212992,208,212992,208,0,0,0,832,4,1,-11,550784,555776,0,0}
	},
	{ //layer050 => layer072
		{1,16,13,1024,1,16,13,512,16,1,0,0,16,0,1,0,208,212992,208,106496,13,1,256,13,416,16,208,1,555776,559104,551720,1241600},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,555776,559104,551720,1241600},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,555776,559104,551720,1241600}
	},
	{ //layer051 => layer073 layer074
		{3,16,13,512,1,16,13,1024,16,1,1,0,17,0,1,0,208,106496,208,212992,13,1,1152,13,416,16,208,1,559104,560768,559912,1241856},
		{1,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,212992,208,212992,0,0,0,0,3328,4,0,-11,555776,560768,0,0},
		{0,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,212992,208,212992,208,0,0,0,832,4,1,-11,555776,560768,0,0}
	},
	{ //layer052 => layer075
		{1,16,13,1024,1,16,13,512,16,1,0,0,16,0,1,0,208,212992,208,106496,13,1,256,13,416,16,208,1,560768,564096,633640,1242112},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,560768,564096,633640,1242112},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,560768,564096,633640,1242112}
	},
	{ //layer053 => layer076
		{3,16,13,512,1,16,13,1024,16,1,1,0,17,0,1,0,208,106496,208,212992,13,1,1152,13,416,16,208,1,564096,565760,641832,1242368},
		{0,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,106496,208,212992,208,1,0,0,832,4,1,1,564096,565760,641832,1242368},
		{0,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,106496,208,212992,208,1,0,0,832,4,1,1,564096,565760,641832,1242368}
	},
	{ //layer054 => layer077
		{1,16,13,1024,1,16,13,512,16,1,0,0,16,0,1,0,208,212992,208,106496,13,1,256,13,416,16,208,1,565760,569088,715560,1242624},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,565760,569088,715560,1242624},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,565760,569088,715560,1242624}
	},
	{ //layer055 => layer078
		{3,16,13,512,1,16,13,1024,16,1,1,0,17,0,1,0,208,106496,208,212992,13,1,1152,13,416,16,208,1,569088,570752,723752,1242880},
		{0,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,106496,208,212992,208,1,0,0,832,4,1,1,569088,570752,723752,1242880},
		{0,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,106496,208,212992,208,1,0,0,832,4,1,1,569088,570752,723752,1242880}
	},
	{ //layer056 => layer079
		{1,16,13,1024,1,16,13,512,16,1,0,0,16,0,1,0,208,212992,208,106496,13,1,256,13,416,16,208,1,570752,574080,797480,1243136},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,570752,574080,797480,1243136},
		{0,16,13,512,0,16,13,512,16,0,0,0,0,0,0,0,208,212992,208,106496,208,1,0,0,832,2,1,1,570752,574080,797480,1243136}
	},
	{ //layer057 => layer080
		{3,16,13,512,1,16,13,1024,16,1,1,0,17,0,1,0,208,106496,208,212992,13,1,1152,13,416,16,208,1,574080,575744,805672,1243392},
		{0,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,106496,208,212992,208,1,0,0,832,4,1,1,574080,575744,805672,1243392},
		{0,16,13,1024,0,16,13,1024,16,0,0,0,0,0,0,0,208,106496,208,212992,208,1,0,0,832,4,1,1,574080,575744,805672,1243392}
	},
	{ //layer058 => layer081 layer082 layer083
		{1,16,13,1024,1,16,13,256,16,1,0,0,16,0,0,0,208,212992,208,53248,13,1,256,13,416,16,208,1,575744,579072,879400,1243648},
		{0,16,13,256,0,16,13,256,16,0,0,0,0,0,0,0,208,212992,208,53248,208,1,0,0,832,1,1,1,575744,579072,879400,1243648},
		{0,16,13,256,0,16,13,256,16,0,0,0,0,0,0,0,208,212992,208,53248,208,1,0,0,832,1,1,1,575744,579072,879400,1243648}
	},
	{ //layer059 => layer084 layer085 layer086
		{1,16,13,512,1,16,13,256,16,1,0,0,16,0,1,0,208,106496,208,53248,13,1,128,13,416,16,208,1,574080,580736,883496,1243904},
		{0,16,13,256,0,16,13,256,16,0,0,0,0,0,0,0,208,106496,208,53248,208,1,0,0,832,1,1,1,574080,580736,883496,1243904},
		{1,16,13,256,0,32,26,256,28,0,0,0,0,0,0,0,208,53248,832,212992,208,0,0,0,1456,2,2,0,574080,580736,0,0},
	},
	{ //layer060 => layer087
		{1,28,26,768,1,28,26,256,28,1,0,0,28,0,1,0,728,559104,728,186368,26,1,192,26,728,28,728,1,580736,589472,885544,1244160},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,559104,728,186368,208,1,0,0,1456,2,2,1,580736,589472,885544,1244160},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,559104,728,186368,208,1,0,0,1456,2,2,1,580736,589472,885544,1244160}
	},
	{ //layer061 => layer088
		{3,28,26,256,1,28,26,512,28,1,1,0,29,0,1,0,728,186368,728,372736,26,1,576,26,728,28,728,1,589472,592384,888616,1244416},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,186368,728,372736,208,1,0,0,1456,4,2,1,589472,592384,888616,1244416},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,186368,728,372736,208,1,0,0,1456,4,2,1,589472,592384,888616,1244416}
	},
	{ //layer062 => layer089
		{1,28,26,512,1,28,26,256,28,1,0,0,28,0,1,0,728,372736,728,186368,26,1,128,26,728,28,728,1,592384,598208,907048,1244672},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,592384,598208,907048,1244672},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,592384,598208,907048,1244672}
	},
	{ //layer063 => layer090
		{3,28,26,256,1,28,26,512,28,1,1,0,29,0,1,0,728,186368,728,372736,26,1,576,26,728,28,728,1,598208,601120,909096,1244928},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,186368,728,372736,208,1,0,0,1456,4,2,1,598208,601120,909096,1244928},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,186368,728,372736,208,1,0,0,1456,4,2,1,598208,601120,909096,1244928}
	},
	{ //layer064 => layer091
		{1,28,26,512,1,28,26,256,28,1,0,0,28,0,1,0,728,372736,728,186368,26,1,128,26,728,28,728,1,601120,606944,927528,1245184},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,601120,606944,927528,1245184},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,601120,606944,927528,1245184}
	},
	{ //layer065 => layer092
		{3,28,26,256,1,28,26,512,28,1,1,0,29,0,1,0,728,186368,728,372736,26,1,576,26,728,28,728,1,606944,609856,929576,1245440},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,186368,728,372736,208,1,0,0,1456,4,2,1,606944,609856,929576,1245440},
		{0,28,26,512,0,28,26,512,28,0,0,0,0,0,0,0,728,186368,728,372736,208,1,0,0,1456,4,2,1,606944,609856,929576,1245440}
	},
	{ //layer066 => layer093 layer094 layer095
		{1,28,26,512,1,28,26,256,28,1,0,0,28,0,0,0,728,372736,728,186368,26,1,128,26,728,28,728,1,609856,615680,948008,1245696},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,609856,615680,948008,1245696},
		{0,28,26,256,0,28,26,256,28,0,0,0,0,0,0,0,728,372736,728,186368,208,1,0,0,1456,2,2,1,609856,615680,948008,1245696}
	},
	{ //layer067 => layer096 layer097 layer098
		{1,28,26,256,1,28,26,128,28,1,0,0,28,0,1,0,728,186368,728,93184,26,1,64,26,728,28,728,1,606944,618592,950056,1245952},
		{0,28,26,128,0,28,26,128,28,0,0,0,0,0,0,0,728,186368,728,93184,208,1,0,0,1456,1,2,1,606944,618592,950056,1245952},
		{1,28,26,128,0,56,52,128,52,0,0,0,0,0,0,0,728,93184,2912,372736,104,0,0,0,1352,4,0,0,606944,618592,0,0},
	},
	{ //layer068 => layer099
		{1,52,52,384,1,52,52,128,52,1,0,0,52,0,1,0,2704,1038336,2704,346112,52,1,96,52,1352,52,2704,1,618592,634816,950568,1246208},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,1038336,2704,346112,104,1,0,0,1352,4,0,1,618592,634816,950568,1246208},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,1038336,2704,346112,104,1,0,0,1352,4,0,1,618592,634816,950568,1246208}
	},
	{ //layer069 => layer100
		{3,52,52,128,1,52,52,256,52,1,1,0,53,0,1,0,2704,346112,2704,692224,52,1,288,52,1352,52,2704,1,634816,640224,951336,1246464},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,346112,2704,692224,104,1,0,0,1352,8,0,1,634816,640224,951336,1246464},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,346112,2704,692224,104,1,0,0,1352,8,0,1,634816,640224,951336,1246464}
	},
	{ //layer070 => layer101
		{1,52,52,256,1,52,52,128,52,1,0,0,52,0,1,0,2704,692224,2704,346112,52,1,64,52,1352,52,2704,1,640224,651040,955944,1246720},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,640224,651040,955944,1246720},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,640224,651040,955944,1246720}
	},
	{ //layer071 => layer102
		{3,52,52,128,1,52,52,256,52,1,1,0,53,0,1,0,2704,346112,2704,692224,52,1,288,52,1352,52,2704,1,651040,656448,956456,1246976},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,346112,2704,692224,104,1,0,0,1352,8,0,1,651040,656448,956456,1246976},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,346112,2704,692224,104,1,0,0,1352,8,0,1,651040,656448,956456,1246976}
	},
	{ //layer072 => layer103
		{1,52,52,256,1,52,52,128,52,1,0,0,52,0,1,0,2704,692224,2704,346112,52,1,64,52,1352,52,2704,1,656448,667264,961064,1247232},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,656448,667264,961064,1247232},
		{0,52,52,128,0,52,52,128,52,0,0,0,0,0,0,0,2704,692224,2704,346112,104,1,0,0,1352,4,0,1,656448,667264,961064,1247232}
	},
	{ //layer073 => layer104
		{3,52,52,128,1,52,52,256,52,1,1,0,53,0,1,0,2704,346112,2704,692224,52,1,288,52,1352,52,2704,1,667264,672672,961576,1247488},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,346112,2704,692224,104,1,0,0,1352,8,0,1,667264,672672,961576,1247488},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,346112,2704,692224,104,1,0,0,1352,8,0,1,667264,672672,961576,1247488}
	},
	{ //layer074 => layer105 layer106
		{1,52,52,256,1,52,52,256,52,1,0,0,52,0,0,0,2704,692224,2704,692224,52,1,64,52,1352,52,2704,1,672672,683488,966184,1247744},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,104,1,0,0,1352,8,0,1,672672,683488,966184,1247744},
		{0,52,52,256,0,52,52,256,52,0,0,0,0,0,0,0,2704,692224,2704,692224,104,1,0,0,1352,8,0,1,672672,683488,966184,1247744}
	}
};
const int in_offset_map[75] = {
	0, //layer 0
	43264, //layer 1
	129792, //layer 2
	173056, //layer 3
	194688, //layer 4
	237952, //layer 5
	259584, //layer 6
	270400, //layer 7
	292032, //layer 8
	302848, //layer 9
	324480, //layer 10
	335296, //layer 11
	340704, //layer 12
	351520, //layer 13
	356928, //layer 14
	367744, //layer 15
	373152, //layer 16
	383968, //layer 17
	389376, //layer 18
	400192, //layer 19
	405600, //layer 20
	416416, //layer 21
	421824, //layer 22
	432640, //layer 23
	438048, //layer 24
	448864, //layer 25
	454272, //layer 26
	465088, //layer 27
	470912, //layer 28
	473824, //layer 29
	479648, //layer 30
	482560, //layer 31
	488384, //layer 32
	491296, //layer 33
	497120, //layer 34
	500032, //layer 35
	505856, //layer 36
	508768, //layer 37
	514592, //layer 38
	517504, //layer 39
	523328, //layer 40
	526240, //layer 41
	532064, //layer 42
	534976, //layer 43
	540800, //layer 44
	544128, //layer 45
	545792, //layer 46
	549120, //layer 47
	550784, //layer 48
	554112, //layer 49
	555776, //layer 50
	559104, //layer 51
	560768, //layer 52
	564096, //layer 53
	565760, //layer 54
	569088, //layer 55
	570752, //layer 56
	574080, //layer 57
	575744, //layer 58
	579072, //layer 59
	580736, //layer 60
	589472, //layer 61
	592384, //layer 62
	598208, //layer 63
	601120, //layer 64
	606944, //layer 65
	609856, //layer 66
	615680, //layer 67
	618592, //layer 68
	634816, //layer 69
	640224, //layer 70
	651040, //layer 71
	656448, //layer 72
	667264, //layer 73
	672672 //layer 74
};
const int out_offset_map[75] = {
	43264, //layer 0
	129792, //layer 1
	173056, //layer 2
	194688, //layer 3
	237952, //layer 4
	259584, //layer 5
	270400, //layer 6
	292032, //layer 7
	302848, //layer 8
	324480, //layer 9
	335296, //layer 10
	340704, //layer 11
	351520, //layer 12
	356928, //layer 13
	367744, //layer 14
	373152, //layer 15
	383968, //layer 16
	389376, //layer 17
	400192, //layer 18
	405600, //layer 19
	416416, //layer 20
	421824, //layer 21
	432640, //layer 22
	438048, //layer 23
	448864, //layer 24
	454272, //layer 25
	465088, //layer 26
	470912, //layer 27
	473824, //layer 28
	479648, //layer 29
	482560, //layer 30
	488384, //layer 31
	491296, //layer 32
	497120, //layer 33
	500032, //layer 34
	505856, //layer 35
	508768, //layer 36
	514592, //layer 37
	517504, //layer 38
	523328, //layer 39
	526240, //layer 40
	532064, //layer 41
	534976, //layer 42
	540800, //layer 43
	544128, //layer 44
	545792, //layer 45
	549120, //layer 46
	550784, //layer 47
	554112, //layer 48
	555776, //layer 49
	559104, //layer 50
	560768, //layer 51
	564096, //layer 52
	565760, //layer 53
	569088, //layer 54
	570752, //layer 55
	574080, //layer 56
	575744, //layer 57
	579072, //layer 58
	580736, //layer 59
	589472, //layer 60
	592384, //layer 61
	598208, //layer 62
	601120, //layer 63
	606944, //layer 64
	609856, //layer 65
	615680, //layer 66
	618592, //layer 67
	634816, //layer 68
	640224, //layer 69
	651040, //layer 70
	656448, //layer 71
	667264, //layer 72
	672672, //layer 73
	683488 //layer 74
};
const int weights_offset_map[75] = {
	0, //layer 0
	72, //layer 1
	360, //layer 2
	392, //layer 3
	680, //layer 4
	1832, //layer 5
	1960, //layer 6
	3112, //layer 7
	3240, //layer 8
	4392, //layer 9
	9000, //layer 10
	9512, //layer 11
	14120, //layer 12
	14632, //layer 13
	19240, //layer 14
	19752, //layer 15
	24360, //layer 16
	24872, //layer 17
	29480, //layer 18
	29992, //layer 19
	34600, //layer 20
	35112, //layer 21
	39720, //layer 22
	40232, //layer 23
	44840, //layer 24
	45352, //layer 25
	49960, //layer 26
	68392, //layer 27
	70440, //layer 28
	88872, //layer 29
	90920, //layer 30
	109352, //layer 31
	111400, //layer 32
	129832, //layer 33
	131880, //layer 34
	150312, //layer 35
	152360, //layer 36
	170792, //layer 37
	172840, //layer 38
	191272, //layer 39
	193320, //layer 40
	211752, //layer 41
	213800, //layer 42
	232232, //layer 43
	305960, //layer 44
	314152, //layer 45
	387880, //layer 46
	396072, //layer 47
	469800, //layer 48
	477992, //layer 49
	551720, //layer 50
	559912, //layer 51
	633640, //layer 52
	641832, //layer 53
	715560, //layer 54
	723752, //layer 55
	797480, //layer 56
	805672, //layer 57
	879400, //layer 58
	883496, //layer 59
	885544, //layer 60
	888616, //layer 61
	907048, //layer 62
	909096, //layer 63
	927528, //layer 64
	929576, //layer 65
	948008, //layer 66
	950056, //layer 67
	950568, //layer 68
	951336, //layer 69
	955944, //layer 70
	956456, //layer 71
	961064, //layer 72
	961576, //layer 73
	966184 //layer 74
};
const int index_conv[75] = {
	0, //layer 0
	1, //layer 1
	2, //layer 2
	3, //layer 3
	5, //layer 4
	6, //layer 5
	7, //layer 6
	9, //layer 7
	10, //layer 8
	12, //layer 9
	13, //layer 10
	14, //layer 11
	16, //layer 12
	17, //layer 13
	19, //layer 14
	20, //layer 15
	22, //layer 16
	23, //layer 17
	25, //layer 18
	26, //layer 19
	28, //layer 20
	29, //layer 21
	31, //layer 22
	32, //layer 23
	34, //layer 24
	35, //layer 25
	37, //layer 26
	38, //layer 27
	39, //layer 28
	41, //layer 29
	42, //layer 30
	44, //layer 31
	45, //layer 32
	47, //layer 33
	48, //layer 34
	50, //layer 35
	51, //layer 36
	53, //layer 37
	54, //layer 38
	56, //layer 39
	57, //layer 40
	59, //layer 41
	60, //layer 42
	62, //layer 43
	63, //layer 44
	64, //layer 45
	66, //layer 46
	67, //layer 47
	69, //layer 48
	70, //layer 49
	72, //layer 50
	73, //layer 51
	75, //layer 52
	76, //layer 53
	77, //layer 54
	78, //layer 55
	79, //layer 56
	80, //layer 57
	81, //layer 58
	84, //layer 59
	87, //layer 60
	88, //layer 61
	89, //layer 62
	90, //layer 63
	91, //layer 64
	92, //layer 65
	93, //layer 66
	96, //layer 67
	99, //layer 68
	100, //layer 69
	101, //layer 70
	102, //layer 71
	103, //layer 72
	104, //layer 73
	105 //layer 74
};
