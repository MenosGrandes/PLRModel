#include "PupilLifecycle.h"

float pupilDiameterInMM = 7.1; // Starts with a large pupil in mm. 
float lightIntensityInBlondels = -2; // Light intensity reaching the retina in Blondels
float timeInMilliseconds = 0; // time

PamplonaAndOliveiraModel model; // PupilLightReflex Model.

float getIntensityInLumens() {
    return Conversion::blondelToLumensSquareMillimeter(powf(10,lightIntensityInBlondels));
}

float evaluateDiameter() {
    pupilDiameterInMM = model.pupilDiameterAt(getIntensityInLumens(), 250, timeInMilliseconds);
    timeInMilliseconds += 100;
    	 
    return pupilDiameterInMM;
}

int main(int argc, char *argv[]) {

    // Fill t<0 data. 
    for (int i=0; i<10; i ++) {
 	 model.addPulse(timeInMilliseconds, getIntensityInLumens(), Conversion::diameterToArea(pupilDiameterInMM));
 	 timeInMilliseconds += 100;
    }

    lightIntensityInBlondels = -2;
    timeInMilliseconds=0;
    for (int i=0; i<20; i ++) {	
	    std::cout <<timeInMilliseconds<<" " 
		      <<lightIntensityInBlondels<<" "
		      << evaluateDiameter() << std::endl;
    }

    lightIntensityInBlondels++;

    for (int i=0; i<50; i ++) {	
	    std::cout <<timeInMilliseconds<<" " 
		      <<lightIntensityInBlondels<<" "
		      << evaluateDiameter() << std::endl;
    }
    
    lightIntensityInBlondels++;

    for (int i=0; i<50; i ++) {	
	    std::cout <<timeInMilliseconds<<" " 
		      <<lightIntensityInBlondels<<" "
		      << evaluateDiameter() << std::endl;
    }
    lightIntensityInBlondels+=-3;

    for (int i=0; i<50; i ++) {	
	    std::cout <<timeInMilliseconds<<" " 
		      <<lightIntensityInBlondels<<" "
		      << evaluateDiameter() << std::endl;
    }
    return 0;
}