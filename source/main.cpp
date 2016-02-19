#include <stdlib.h>
#include "GitHub.h"

using namespace GitHubAPI;

int main(int argc , char *argv[])
{
    GitHub gitHub;
    gitHub.connect();
    
    return 0;
}
