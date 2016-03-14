/* 
 * stuff
 */

#include <cstdlib>
#include <cstddef>
#include <stdexcept>
#include <iostream>

#include <SoapySDR/Version.hpp>
#include <SoapySDR/Modules.hpp>
#include <SoapySDR/Registry.hpp>
#include <SoapySDR/Device.hpp>

using namespace std;

bool verbose=true;
size_t channel;

extern "C" SoapySDR::Device* soapy_open_dev(size_t dev_idx) {
    SoapySDR::KwargsList devs = SoapySDR::Device::enumerate("");
    if (verbose) {
        for (size_t t=0;t<devs.size();t++) {
            cout<<"Found device "<<t<<" (";
            for (SoapySDR::Kwargs::iterator it=devs[t].begin(); it!=devs[t].end(); ++it) {
                cout<<it->first<<"="<< it->second;
                if (*it!=*(devs[t].rbegin())) cout<<", ";
            }
            cout<<")"<<endl;
        }
    }
    if (devs.size()==0) throw runtime_error("No SDR devices to choose from");

    if (dev_idx<0 || dev_idx>=devs.size()) throw runtime_error("Selected device index is not available");
    SoapySDR::Kwargs filter=devs[dev_idx];
    SoapySDR::Device *dev=SoapySDR::Device::make(filter);
    if (verbose) cout<<"Selected device with driver "<<dev->getDriverKey()<<endl;

    if (dev->getNumChannels(SOAPY_SDR_RX)<=0) throw runtime_error("sdr device has no RX channel");
    channel=0;

    return dev;
}

extern "C" double soapy_set_sr(SoapySDR::Device *dev,double sr) {
    dev->setSampleRate(SOAPY_SDR_RX,channel,sr);
    double gotsr=dev->getSampleRate(SOAPY_SDR_RX,channel);
    if (verbose) cout<<"got sample rate "<<gotsr<<endl;
    //if (abs(gotsr-sr)>100) throw runtime_error("could not set sample rate close enough");
    return gotsr;
}

extern "C" double soapy_set_rf(SoapySDR::Device *dev,double f) {
    dev->setFrequency(SOAPY_SDR_RX, channel, f);
    double gotf=dev->getFrequency(SOAPY_SDR_RX,channel);
    if (verbose) cout<<"got frequency "<<gotf<<endl;
    return gotf;
}


void print_arginfo(const SoapySDR::ArgInfo& ai) {
    /*
    string key=arginfo.key;
    string defval=arginfo.value;
    string name=arginfo.name;
    string description=arginfo.description;
    string units=arginfo.units;
    */
    cout<<ai.name<<"("<<ai.key<<") default "<<ai.value<<" units "<<ai.units<<"description "<<ai.description;
}

int main(int argc, char *argv[]) {
    SoapySDR::Device *dev=soapy_open_dev(0);

    double sr=2000000;
    double gotsr=soapy_set_sr(dev,sr);
    if (abs(gotsr-sr)>100) throw runtime_error("could not set sample rate close enough");

    soapy_set_rf(dev,1090.0e6);

    SoapySDR::ArgInfoList arginfos=dev->getStreamArgsInfo(SOAPY_SDR_RX,channel);
    cout<<"device channel 0 has "<<arginfos.size()<<" args"<<endl;
    for (size_t t=0;t<arginfos.size();t++) {
        print_arginfo(arginfos[t]);
    }
}

