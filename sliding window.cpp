#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FRAMES 500

void sender(int frame_size);
void receiver(int frame);

int main() {
    int window_size, frame_size, sent_frames = 0;

    printf("Enter the total number of frames: ");
    scanf("%d", &frame_size);

    printf("Enter the window size: ");
    scanf("%d", &window_size);

    while (sent_frames < frame_size) {
        printf("\n----Sending Window----\n");

        // Send frames within the window size
        for (int i = 0; i < window_size && sent_frames < frame_size; i++) {
            printf("Sending frame %d\n", sent_frames + 1);
            sent_frames++;
        }

        printf("\n----Receiving Window----\n");

        // Simulate acknowledgment for the sent frames
        for (int i = 0; i < window_size && sent_frames - window_size + i < frame_size; i++) {
            printf("Acknowledgment received for frame %d\n", sent_frames - window_size + i + 1);
        }
    }

    printf("\nAll frames sent and acknowledged.\n");
    return 0;
}
