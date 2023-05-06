#include <unistd.h>
#include "cprogressbar.h"

int main(){
    CProgressbar cprogressbar(100, 1, 1);
    for(int i=0; i<100; i++){
        cprogressbar.increment();
        cprogressbar.show("hello");
        usleep(50 * 1000);
    }
}
