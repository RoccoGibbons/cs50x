#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv){
    //I'm not sure, I've googled and looked around and everyone seems to have done this but when
    //I play it, it seems to be normal when I type 1 but otherwise it seems to either not produce
    //sound or become much worse quality sound - not changing volume.
    const int headerSize = 44;
    
    if(argc != 4){
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");
    float factor = atof(argv[3]);

    if(input == NULL || output == NULL){
        printf("Could not open file\n");
        return 1;
    }

    uint8_t header[headerSize];
    fread(header, headerSize, 1, input);
    fwrite(header, headerSize, 1, output);

    int16_t buffer;

    while(fread(&buffer, sizeof(int16_t), 1, input)) {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    fclose(input);
    fclose(output);
}