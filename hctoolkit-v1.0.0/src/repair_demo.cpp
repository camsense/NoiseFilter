

#include <stdio.h>
#include <iostream>
#include <string> 
#include <sstream>
#include <algorithm>
#include <fstream>

#include "base/Hctoolkit.h"

int main()
{
    int rtn = 0;

    string ss = GetVer();
	
	//If need Filter 
	hcSDKFltInitialize();
	printf("hcSDKFltInitialize() complete\n");	
   
    //To update lidar paras of model "X2B" 
    stFltLidarCfg_t stLidarPara;
	bool bLowSpinSpeed = false;     
	if(UpdateLidarPara("X2B", bLowSpinSpeed, stLidarPara))  
	{
		printf("The stLidar Para with default value\n");	
	}		
	
	//The tsPtClouds of 1-circle Point Clouds to be processed  	
	std::vector<stPtCloud_t> tsPtClouds;
	printf("‘tsPtClouds’ size is  %d \n",tsPtClouds.size());
	
	//Can Overwrite stFltGblSetting or stFltLParas here, 
	//or with the default value which defined with micro-Define in HcPointCloudData.h
	stFltGblSetting_t stFltGblSetting;
	stFltLParas_t stFltLParas;
    stFltGblSetting.fFacAdjHSpd = 3.0;
	stFltLParas.nActDist = 1000;

	//Call Filter function
	hotPixelFilter(tsPtClouds, stLidarPara, stFltGblSetting, stFltLParas);      
    printf("Result Data in 'tsPtClouds' \n"); 

	//If need Filter, to Close modoule  
	hcSDKFltUnInit();

	getchar();
    return 0;
}
