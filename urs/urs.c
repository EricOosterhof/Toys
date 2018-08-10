#include <stdio.h>

typedef unsigned int uint;

uint i = 0;

typedef struct timingConversion {
   uint fudgeFactor;        //added to delay to account for FPGA constant
   uint aggregationFactor;  // This represent the delay for a video signal (frame sync) to pass
   // from an XIO-4901 then going to aggregation port , returning to the aggregation port using
   // loop back cable up to the receiver ip_player ( configure with a 4 packet start up level).
   uint videoLinePeriod; // number of nanoseconds in a line of video
   uint packetDuration;  // nanoseconds per packet of video
   uint rfc4175DecapFudgeFactor;  // This value in nano second was measured with an scope. It represents the time
   // between ninkasi TOF and the actual beginning of the frame at the output of the rfc4175decap

   uint packetTime;		// packet time in ns
   uint lineTime;			// line time in ns
   uint ursDelay;			// delay caused by the URS v. PTP timing issue
   uint ninkasiFudge;		// Ninkasi delay fudge factor in ns - basically how long to get through the ninkasi
   uint porterFudge;		// Porter delay fudge factor
   uint citraFudge;		// Citra delay fudge factor
} timingConversion;

/*
  videoLinePeriod = FrameRate(mSecond)/TotalNumberOfLines
  SMPTE 2022: NumberOfPixelsPerPacket = 550.4
  RFC-4175:   NumberOfPixelsPerPacket = 480
  packetDuration = videoLinePeriod / (TotalPixelsPerLine/NumberOfPixelsPerPacket)

  The ordering of these entries must match the definition of
  VitDelaySelect_t. All values are in units of nanoseconds.
  Table for SMPTE2022
*/
/*
 * For these:
 * 	h - horizontal
 * 	v - vertical
 * 	f - freq * 100 in hz
 */
#define PIXEL_TIME(h,v,f)		((float) ( ( (float)(1e9)*(float)100) / ((float)h * (float)v * (float)f)) )
#define PKT_TIME_2022(h, v, f)		((uint)(550.4 * PIXEL_TIME(h,v,f)))
#define PKT_TIME_2110(h, v, f)		((uint)(480.0 * PIXEL_TIME(h,v,f)))
#define LINE_TIME(h,v,f)		((uint)(h * PIXEL_TIME(h,v,f)))

// URS delay in nS
#define URS_NTSC	( 9700 )
#define URS_PAL		( 10200 )

timingConversion convTbl_2022[] = {
   { 4894, 850000,           63556, 40770, 0,	PKT_TIME_2022(858,525,2997), 	LINE_TIME(858,525,2997), 	URS_NTSC, 0,0,0		},  //  525i2997
   { 7238, 150000,           22244,  7420, 0,	PKT_TIME_2022(1650,750,5994), 	LINE_TIME(1650,750,5994), 	URS_NTSC, 0,0,0		},  //  720p5994
   { 7538, 110000,           29660,  7420, 0,	PKT_TIME_2022(2200,1125,2997), 	LINE_TIME(2200,1125,2997), 	URS_NTSC, 0,0,0		},  // 1080i2997
   { 9331, 70000,            14830,  3710, 0,	PKT_TIME_2022(2200,1125,5994), 	LINE_TIME(2200,1125,5994), 	URS_NTSC, 0,0,0		},  // 1080p5994
   { 5469, 636000,           64000, 40770, 0,	PKT_TIME_2022(864,625,2500), 	LINE_TIME(864,625,2500), 	URS_PAL, 0,0,0		},  //  625i25
   { 3206, 160000,           26666,  7413, 0,	PKT_TIME_2022(1980,750,5000), 	LINE_TIME(1980,750,5000), 	URS_PAL, 0,0,0		},  //  720p50
   { 2025, 150000,           35556,  7413, 0,	PKT_TIME_2022(2640,1125,2500),	LINE_TIME(2640,1125,2500),	URS_PAL, 0,0,0		},  // 1080i25
   { 6825, 60000,            17778,  3706, 0,	PKT_TIME_2022(2640,1125,5000), 	LINE_TIME(2640,1125,5000),	URS_PAL, 0,0,0		},  // 1080p50
   { 7538, (91980 + 7420),   29660,  7413, 0,	0,0,0, 0,0,0		},  // 1080pSF2398 (1080i numbers, FIXME!)
   { 6825, (53000 + 3706),   17778,  7407, 0,	0,0,0, 0,0,0		},  // 1080pSF24 (meaningless, here for symetry)
};


// Table for RFC4175 (ST2110)
timingConversion convTbl_2110[] = {
   { 4894, 850000,           63556, 40770, 0,	PKT_TIME_2110(858,525,2997), 	LINE_TIME(858,525,2997), 	URS_NTSC, 0,0,0		},  //  525i2997
   { 7238, 150000,           22244,  7420, 0,	PKT_TIME_2110(1650,750,5994), 	LINE_TIME(1650,750,5994), 	URS_NTSC, 0,0,0		},  //  720p5994
   { 7538, 110000,           29660,  7420, 0,	PKT_TIME_2110(2200,1125,2997), 	LINE_TIME(2200,1125,2997), 	URS_NTSC, 0,0,0		},  // 1080i2997
   { 9331, 70000,            14830,  3710, 0,	PKT_TIME_2110(2200,1125,5994), 	LINE_TIME(2200,1125,5994), 	URS_NTSC, 0,0,0		},  // 1080p5994
   { 5469, 636000,           64000, 40770, 0,	PKT_TIME_2110(864,625,2500), 	LINE_TIME(864,625,2500), 	URS_PAL, 0,0,0		},  //  625i25
   { 3206, 160000,           26666,  7413, 0,	PKT_TIME_2110(1980,750,5000), 	LINE_TIME(1980,750,5000), 	URS_PAL, 0,0,0		},  //  720p50
   { 2025, 150000,           35556,  7413, 0,	PKT_TIME_2110(2640,1125,2500),	LINE_TIME(2640,1125,2500),	URS_PAL, 0,0,0		},  // 1080i25
   { 6825, 60000,            17778,  3706, 0,	PKT_TIME_2110(2640,1125,5000), 	LINE_TIME(2640,1125,5000),	URS_PAL, 0,0,0		},  // 1080p50
   { 7538, (91980 + 7420),   29660,  7413, 0,	0,0,0, 0,0,0		},  // 1080pSF2398 (1080i numbers, FIXME!)
   { 6825, (53000 + 3706),   17778,  7407, 0,	0,0,0, 0,0,0		},  // 1080pSF24 (meaningless, here for symetry)
};


char *format[] = {
   "525i2997 512",
   "720p5994    ",
   "1080i2997   ",
   "1080p5994   ",
   "625i25   608",
   "720p50      ",
   "1080i25     ",
   "1080p50     ",
   "1080pSF2398 ",
   "1080pSF24   ",
};

int
main(int argc, char**argv)
{
   int i;
   

   printf("\n2022\n");
   printf("\t\t TIMEp \t\t TIMEl \t\t URS\n");
   for ( int i = 0 ; i < 10 ; i++ ) {
      printf("%s\t%8.8d\t%8.8d\t%8.8d\n", format[i],convTbl_2022[i].packetTime, convTbl_2022[i].lineTime, convTbl_2022[i].ursDelay);
   }

   
   printf("\n2110\n");
   printf("\t\t TIMEp \t\t TIMEl \t\t URS\n");
   for ( int i = 0 ; i < 10 ; i++ ) {
      printf("%s\t%8.8d\t%8.8d\t%8.8d\n", format[i],convTbl_2110[i].packetTime, convTbl_2110[i].lineTime, convTbl_2110[i].ursDelay);
   }


      
   ;   
   
}
