#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    // prompts user for pyramid height between 1 and 23
    do
    {
        height = get_int("Please specify the height of the pyramid: ");
    }
    while (height <= 0 || height > 8);

    // for loops specifying number of spaces and hashes per line
    for (int line = 0; line < height; line++)
    {
        for (int spaces = height - line; spaces > 1; spaces--)
        {
            //Spaces before first half of pyramid.
            printf(" ");
        }
        for (int hashes = 0; hashes < line + 1; hashes++)
        {
            //First half of Pyramid
            printf("#");
        }
        //Space between pyramids.
        printf("  ");
        for (int hashes = 0 ; hashes < line + 1; hashes++)
        {
            //Second Pyramid
            printf("#");
        }
        //New line at the end
        printf("\n");
    }
}
