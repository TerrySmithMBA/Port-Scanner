//Author: Terry D. Smith II, MBA MSIT
//Classification: 1 Hour Self-Administered Challenge
//Date: 28 DECEMBER 2018
//Completed: 56 Minutes and 24 Seconds




#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main (){
    //Should prompt the user for an IP
    printf("Please Enter an IP Address \n");
    char IP[16];
    int sock, err;
    scanf("%s", IP);



    //Should prompt the user for a Port Range
    printf("Please Enter the Lowest Port Number within your Port Range \n");
    int lowPort;
    scanf("%d", &lowPort);
    printf("Please Enter the Highest Port Number within your Port Range \n");
    int highPort;
    scanf("%d", &highPort);



    //Port scanner finds open ports by attempting connections.
    struct sockaddr_in socketAddress;
    strncpy((char*)&socketAddress, "", sizeof socketAddress);
    socketAddress.sin_family = AF_INET;


    
    printf("%s", "Scanning ");
    printf("%s", IP);
    //Port scan loop
    for (int i = lowPort; i <= highPort; i++){
        socketAddress.sin_port = htons(i);
        sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock < 0){
            perror("\nSocket");
        }        

        err = connect(sock, (struct sockaddr*)&socketAddress, sizeof socketAddress);

        if (err < 0) {
            fflush(stdout);
        }
        else {
            printf("\n");
            printf("%-5d open\n", i);
        }
        close(sock);
    }
    printf("\r");
    fflush(stdout);
    return(0);

};