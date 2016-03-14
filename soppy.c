/* 
 * stuff
 */

#include <stdio.h>
#include <SoapySDR/Device.h>

int main(int argc, char *argv[]) {
    int ndevs;
    SoapySDRKwargs *devs=SoapySDRDevice_enumerate(NULL,ndevs);
    for (int t=0;t<ndevs;t++) {
        SoapySDRKwargs *dev=devs[t];
        printf("device %d (",t);
        for (int k=0;k<dev.size;k++) {
            char *key=devs.keys[t];
            char *val=devs.vals[t];
            printf("%s=%s",key,val);
            if (k!=dev.size) printf(", ");
        }
        printf(")\n",t);
    }
}
