#include "PupilLifecycle.h"
#include "json.hpp"
#include <fstream>
#include <queue>
using json = nlohmann::json;

float pupilDiameterInMM = 0; // Starts with a large pupil in mm. 
float lightIntensityInBlondels = -2; // Light intensity reaching the retina in Blondels
float timeInMilliseconds = 100; // time
float timeIntervalMS = 100;
PamplonaAndOliveiraModel model; // PupilLightReflex Model.


class LightTime
{
    public:
    LightTime(float _lightIntensityInBlondels,float _timeMS):timeMS(_timeMS),lightIntensityInBlondels(_lightIntensityInBlondels){};
    float lightIntensityInBlondels;
    float timeMS;
};
std::queue<LightTime> changesQueue;


float getIntensityInLumens() {
    return Conversion::blondelToLumensSquareMillimeter(powf(10,lightIntensityInBlondels));
}

float evaluateDiameter() {
    pupilDiameterInMM = model.pupilDiameterAt(getIntensityInLumens(), 250, timeInMilliseconds);
    timeInMilliseconds += timeIntervalMS;
    	 
    return pupilDiameterInMM;
}
void readJSON(const std::string filename)
{
    std::ifstream i(filename);
    json j;
    i >> j;
    pupilDiameterInMM = j["startingValues"]["pupilDiameterInMM"];
    lightIntensityInBlondels = j["startingValues"]["lightIntensityInBlondels"];
    timeIntervalMS = j["startingValues"]["timeIntervalMS"];

    json queueArray = json::array();
    queueArray = j["changesOfLight"];
    for (auto& element : queueArray) 
    {
       changesQueue.emplace(LightTime(element["light"],element["timeMS"]));
    }
}
int main(int argc, char *argv[]) 
{
    readJSON("settings/settings.json");
    
    
    for (int i=0; i<1; i ++) {
 	 model.addPulse(timeInMilliseconds, getIntensityInLumens(), Conversion::diameterToArea(pupilDiameterInMM));
 	 timeInMilliseconds += 1;
    }
    while(!changesQueue.empty())
    {
        LightTime element = changesQueue.front();
        lightIntensityInBlondels = element.lightIntensityInBlondels;
            for (int i=0; i<static_cast<int>(element.timeMS);i++) 
            {	
            std::cout <<  timeInMilliseconds <<" "
            <<  lightIntensityInBlondels<<" "
            <<  evaluateDiameter() << std::endl;
            }
            changesQueue.pop();
    }

    return 0;
}