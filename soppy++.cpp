/* 
 * stuff
 */

#include <cstdlib>
#include <cstddef>
#include <iostream>

#include <SoapySDR/Version.hpp>
#include <SoapySDR/Modules.hpp>
#include <SoapySDR/Registry.hpp>
#include <SoapySDR/Device.hpp>


int main(int argc, char *argv[]) {
    SoapySDR::KwargsList devs = SoapySDR::Device::enumerate("");
    for (size_t t=0;t<devs.size();t++) {
        std::cout<<"Found device "<<t<<" (";
        for (SoapySDR::Kwargs::const_iterator it=devs[t].begin(); it!=devs[t].end(); ++it) {
            std::cout<<it->first<<"="<< it->second<<", ";
        }
        std::cout<<std::endl;
    }
}
