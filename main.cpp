#include <iostream>
#include <windows.h>

//function of e key being pressed
void eKey()
{
    static SHORT key;
    static UINT mappedkey;
    static INPUT input = { 0 };
    key = VkKeyScan('e');
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));

}


//function of r key being pressed
void rKey()
{
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 };
    key = VkKeyScan('r');
    mappedkey = MapVirtualKey(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}



int main()
{   // looping for reasons beyond scope

    std::cout << "NUMPAD 2 -> START\nNUMPAD 0 -> STOP" << std::endl;


    while (true)
    {   
        //adding 50ms of delay so that the compiler doesnt extract multiple clicks
        Sleep(50);


        //pressing NUMPAD2 activates the loop and autoclicker
        if (GetAsyncKeyState(VK_NUMPAD2))
        {
            std::cout << "NUMPAD2 PRESSED" << std::endl;


            //for pressing infintely until terminated
            while (true)
            {
                //rKey();
                //50 seconds delay so as not to be flagged as bot
                //could add a rng generator to further reduce detections by anticheat
                Sleep(60);

                eKey();
       


                //ending compilation with NUMPAD0 to stop autoclicker
                if (GetAsyncKeyState(VK_NUMPAD0))
                {
                    std::cout << "NUMPAD0 PRESSED" << std::endl;
                    break;
            
                }


            }
       
        }


    }


}