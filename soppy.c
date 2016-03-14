/* 
 * stuff
 */

#include <stdio.h>
#include <SoapySDR/Version.h>
#include <SoapySDR/Modules.h>
#include <SoapySDR/Device.h>

int main(int argc, char *argv[]) {
    size_t ndevs;
    SoapySDRKwargs *devs=SoapySDRDevice_enumerate(NULL,&ndevs);
    for (int t=0;t<ndevs;t++) {
        SoapySDRKwargs dev=devs[t];
        printf("device %d (",t);
        for (int k=0;k<dev.size;k++) {
            char *key=dev.keys[t];
            char *val=dev.vals[t];
            printf("%s=%s",key,val);
            if (k!=dev.size) printf(", ");
        }
        printf(")\n");
    }
}
