#include <graphics.h>
#include<math.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<w32api.h>
#include<string>
#include<string.h>
#include <fcntl.h>
#include<fstream>

#define S_N_L (radius-10)        // Second Needle Length
#define S_N_C RED                   // Second needle Color
#define M_N_L (radius-20)           // Minute Needle Length
#define M_N_C LIGHTRED              // Minute Needle Color
#define H_N_L (radius-(radius/2))       // Hour Needle Length
#define H_N_C CYAN                     // Hour Needle Color
#define M_PI 3.1415926535

using namespace std;

float cx,cy;
float radius=100;
int mainWindow;
int hour,minute,second;

void setup_desk();
void update_clock();
void draw_face(float radius);
void get_time(int &h,int &m,int &s);
void second_needle(int s);
void minute_needle(int m,int s);
void hour_needle(int h,int m,int s);
void file_manager();
void sys_info();
void clear_file_list();
void file_list();
void process_management();

int main(){
    mainWindow=initwindow(1350,690);

    int mX,mY;

    setup_desk();

    while(!kbhit()){
        update_clock();
        delay(100);
        getmouseclick(WM_LBUTTONDOWN,mX,mY);

        if(mX>45 && mX<370 && mY>40 && mY<125){     //sys info
            //transfer control to sys info window
            printf("sys info");
            sys_info();
            setup_desk();
        }else if(mX>45 && mX<370 && mY>160 && mY<250){  //file mgr
            //transfer control to file window
            printf("file mgr");
            file_manager();
            setup_desk();
        }else if(mX>45 && mX<370 && mY>290 && mY<377){  //process mgt
            //transfer control to process window
            printf("process mgt");
            process_management();
            setup_desk();
        }

    }

    getch();
    closegraph();
    return 0;
}

//*************** FUNCTIONS DEFINITIONS *****************
void setup_desk(){
    readimagefile("mainUIimp.bmp", 0, 0, 1350, 690);

    cx=1200;
    cy=150;
    // Now the point (cx,cy) is the center of the clock.

    settextstyle(TRIPLEX_FONT,0, 2);
    setbkcolor(DARKGRAY);
    setcolor(WHITE);
    outtextxy(77,75, "System Information");
    outtextxy(120,200, "File Manager");
    outtextxy(70,320, "Process Management");

    draw_face(radius);
}

void process_management(){
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    initwindow(800,492,"Processes",300,100);
    readimagefile("processmgt.bmp",0,0,800,492);

    while(true){
        int mX,mY;
        getmouseclick(WM_LBUTTONDOWN,mX,mY);

        if(mX>89 && mY>79 && mX<245 && mY<214){
            CreateProcess( NULL ,   // No module name (use command line)
                            "cmd.exe /c tasklist && pause",        // Command line
                            NULL,           // Process handle not inheritable
                            NULL,           // Thread handle not inheritable
                            FALSE,          // Set handle inheritance to FALSE
                            CREATE_NEW_CONSOLE,              // No creation flags
                            NULL,           // Use parent's environment block
                            NULL,           // Use parent's starting directory
                            &si,            // Pointer to STARTUPINFO structure
                            &pi );           // Pointer to PROCESS_INFORMATION structure

            // Wait until child process exits.
            WaitForSingleObject( pi.hProcess, INFINITE );

            // Close process and thread handles.
            CloseHandle( pi.hProcess );
            CloseHandle( pi.hThread );

        }else if(mX>341 && mY>80 && mX<494 && mY<208){
            CreateProcess( NULL ,   // No module name (use command line)
                            "cmd.exe /c start iexplore.exe",        // Command line
                            NULL,           // Process handle not inheritable
                            NULL,           // Thread handle not inheritable
                            FALSE,          // Set handle inheritance to FALSE
                            CREATE_NEW_CONSOLE,              // No creation flags
                            NULL,           // Use parent's environment block
                            NULL,           // Use parent's starting directory
                            &si,            // Pointer to STARTUPINFO structure
                            &pi );           // Pointer to PROCESS_INFORMATION structure

            // Wait until child process exits.
            WaitForSingleObject( pi.hProcess, INFINITE );

            // Close process and thread handles.
            CloseHandle( pi.hProcess );
            CloseHandle( pi.hThread );
        }else if(mX>578 && mY>79&& mX<728 && mY<216){
            CreateProcess( NULL ,   // No module name (use command line)
                            "cmd.exe /c start mspaint.exe",        // Command line
                            NULL,           // Process handle not inheritable
                            NULL,           // Thread handle not inheritable
                            FALSE,          // Set handle inheritance to FALSE
                            CREATE_NEW_CONSOLE,              // No creation flags
                            NULL,           // Use parent's environment block
                            NULL,           // Use parent's starting directory
                            &si,            // Pointer to STARTUPINFO structure
                            &pi );           // Pointer to PROCESS_INFORMATION structure

            // Wait until child process exits.
            WaitForSingleObject( pi.hProcess, INFINITE );

            // Close process and thread handles.
            CloseHandle( pi.hProcess );
            CloseHandle( pi.hThread );
        }else if(mX>90 && mY>270 && mX<240 && mY<406){
            CreateProcess( NULL ,   // No module name (use command line)
                            "cmd.exe /c start calc.exe",        // Command line
                            NULL,           // Process handle not inheritable
                            NULL,           // Thread handle not inheritable
                            FALSE,          // Set handle inheritance to FALSE
                            CREATE_NEW_CONSOLE,              // No creation flags
                            NULL,           // Use parent's environment block
                            NULL,           // Use parent's starting directory
                            &si,            // Pointer to STARTUPINFO structure
                            &pi );           // Pointer to PROCESS_INFORMATION structure

            // Wait until child process exits.
            WaitForSingleObject( pi.hProcess, INFINITE );

            // Close process and thread handles.
            CloseHandle( pi.hProcess );
            CloseHandle( pi.hThread );
        }else if(mX>342 && mY>272 && mX<499 && mY<400){
            CreateProcess( NULL ,   // No module name (use command line)
                            "cmd.exe /c start Taskmgr.exe",        // Command line
                            NULL,           // Process handle not inheritable
                            NULL,           // Thread handle not inheritable
                            FALSE,          // Set handle inheritance to FALSE
                            CREATE_NEW_CONSOLE,              // No creation flags
                            NULL,           // Use parent's environment block
                            NULL,           // Use parent's starting directory
                            &si,            // Pointer to STARTUPINFO structure
                            &pi );           // Pointer to PROCESS_INFORMATION structure

            // Wait until child process exits.
            WaitForSingleObject( pi.hProcess, INFINITE );

            // Close process and thread handles.
            CloseHandle( pi.hProcess );
            CloseHandle( pi.hThread );
        }else if(mX>602 && mY>290 && mX<705 && mY<387){
            closegraph(CURRENT_WINDOW);
            setcurrentwindow(mainWindow);
            break;
        }
    }
}

void update_clock(){
    get_time(hour,minute,second);
    hour+=5;minute+=30;
    second_needle(second);
    minute_needle(minute,second);
    hour_needle(hour,minute,second);
    circle(cx,cy,2);
}

void sys_info(){
    initwindow(400,333,"System",400,200);
    readimagefile("SysInfo.bmp",0,0,400,333);
    SYSTEM_INFO siSysInfo;

    // Copy the hardware information to the SYSTEM_INFO structure.

    ::GetSystemInfo(&siSysInfo);

    // Display the contents of the SYSTEM_INFO structure.
    setcolor(BLACK);
    setbkcolor(WHITE);
    outtextxy(30,25,"Hardware information:");
    bgiout<<"OEM ID: "<<siSysInfo.dwOemId;
    outstreamxy(30,55);
    bgiout<<"Number of processors: "<<siSysInfo.dwNumberOfProcessors;
    outstreamxy(30,85);
    bgiout<<"Page size: "<< siSysInfo.dwPageSize;
    outstreamxy(30,115);
    bgiout<<"Processor type: "<<siSysInfo.dwProcessorType;
    outstreamxy(30,145);
    bgiout<<"Minimum application address: "<<siSysInfo.lpMinimumApplicationAddress;
    outstreamxy(30,175);
    bgiout<<"Maximum application address: "<<siSysInfo.lpMaximumApplicationAddress;
    outstreamxy(30,205);
    bgiout<<"Active processor mask: "<<siSysInfo.dwActiveProcessorMask;
    outstreamxy(30,235);
    while(true){
        int mX,mY;
        getmouseclick(WM_LBUTTONDOWN,mX,mY);
        if(mX!=-1){
            closegraph(CURRENT_WINDOW);
            setcurrentwindow(mainWindow);
            break;
        }
    }
}

void clear_file_list(){
    outstreamxy(65,83);
    outstreamxy(65,83);
    for(int i=0;i<10;i++){
        setbkcolor(WHITE);
        setcolor(BLACK);
        bgiout<<"                                           ";
        outstreamxy(65,83+(i*20));
    }
}

void file_list(){
    char names[50][30];
    fstream myfiles;
    myfiles.open ("filenames.txt",ios::in);
    int n=0;
    while(myfiles){
        myfiles>>names[n];
        n++;
    }
    n--;
    myfiles.close();
    outstreamxy(65,83);
    outstreamxy(65,83);
    setbkcolor(WHITE);
    setcolor(BLACK);
    for(int i=0;i<n;i++){
        bgiout<<names[i];
        outstreamxy(65,83+(i*20));
    }
}

void file_manager(){
    initwindow(797, 492,"Files",150,100);
    readimagefile("filemgr.bmp",0,0,797, 492);
    file_list();
    file_list();

    char inputbuf[25]="";
    while(true){
        int mX,mY;
        getmouseclick(WM_LBUTTONDOWN,mX,mY);

        if(mX>540 && mX<747 && mY>76 && mY<111){        //text box
            setbkcolor(WHITE);
            setcolor(BLACK);
            inputbuf[0]=0;
            char blank[25]="                        ";
            int input_pos = 0;
            int the_end = 0;
            outstreamxy(543,79);
            bgiout<<blank;
            outstreamxy(543,79);
            while (!the_end){
               char c = getch();
               switch (c)
               {
                    case 8: //* backspace
                      if (input_pos)
                      {
                         input_pos--;
                         inputbuf[input_pos] = 0;
                         outstreamxy(543,79);
                         bgiout<<blank;
                         outstreamxy(543,79);
                         bgiout<<inputbuf;
                      }
                      break;
                    case 13: //* return
                      the_end = 1;
                      break;
                    case 27: //* Escape = Abort
                      the_end = 1;
                      break;
                    default:
                      if (input_pos < 25-1 && c >= ' ' && c <= '~')
                      {
                         inputbuf[input_pos] = c;
                         input_pos++;
                         inputbuf[input_pos] = 0;
                         //inputbuf[input_pos] = 0;
                         outstreamxy(543,79);
                         bgiout<<blank;
                         outstreamxy(543,79);
                         bgiout<<inputbuf;
                      }
               }
               outstreamxy(543,79);
               bgiout<<inputbuf;
               outstreamxy(543,79);
            }

        }else if(mX>540 && mX<747 && mY>149 && mY<194){        //create file
            if(inputbuf[0]!=0){
                char filename[300]="";
                strcat(filename,inputbuf);
                strcat(filename,".txt");
                int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                close(fd);
                fstream myfile;
                myfile.open ("filenames.txt",ios::out|ios::app);
                myfile << "\n"<<filename;
                myfile.close();
                clear_file_list();
                file_list();
                file_list();
            }
        }else if(mX>540 && mX<747 && mY>232 && mY<276){        //read file
            char read[200]="notepad.exe ";
            strcat(read,inputbuf);
            strcat(read,".txt");
            system(read);
        }else if(mX>540 && mX<747 && mY>311 && mY<355){        //update file
            char read[200]="notepad.exe ";
            strcat(read,inputbuf);
            strcat(read,".txt");
            system(read);
        }else if(mX>540 && mX<747 && mY>387 && mY<433){        //exit
            closegraph(CURRENT_WINDOW);
            setcurrentwindow(mainWindow);
            break;
        }
    }
}

void draw_face(float radius){
    int theta=0; // theta is the angle variable.
    float x,y;
    circle(cx,cy,radius+24);
    circle(cx,cy,radius+23);
    setcolor(BROWN);
    for(int i=0;i<9;i++)
        circle(cx,cy,radius+13+i);
    setcolor(WHITE);
    circle(cx,cy,radius+12);
    circle(cx,cy,radius+10);

    circle(cx,cy,2);
    int i=0;
    //** DRAW NUMERIC POINTS **
    do{
        x=cx+radius*cos(theta*M_PI/180);
        y=cy+radius*sin(theta*M_PI/180);

        circle(x,y,2);
        circle(x+5,y,0);
        circle(x-5,y,0);
        circle(x,y+5,0);
        circle(x,y-5,0);

        theta+=30;
        i++;
    }while(i!=12); //LIMIT NUMERIC POINTS UPTO =12= Numbers.
    i=0;

    do{
        putpixel(cx+radius*cos(i*M_PI/180),cy+radius*sin(i*M_PI/180),DARKGRAY);
        i+=6;
    }while(i!=360);

}

//** Function to get the current time. **
void get_time(int &h,int &m,int &s){
    time_t rawtime;
    struct tm *t;
    time(&rawtime);
    t = gmtime(&rawtime);
    h=t->tm_hour;
    m=t->tm_min;
    s=t->tm_sec;
}

//** Function to draw Second needle. **
void second_needle(int s){
    float angle=-90;
    float sx,sy;
    setcolor(0);
    sx=cx+S_N_L*cos((angle+s*6-6)*M_PI/180);
    sy=cy+S_N_L*sin((angle+s*6-6)*M_PI/180);
    line(cx,cy,sx,sy);
    setcolor(S_N_C);
    sx=cx+S_N_L*cos((angle+s*6)*M_PI/180);
    sy=cy+S_N_L*sin((angle+s*6)*M_PI/180);
    line(cx,cy,sx,sy);
}

//** Function to draw Minute needle. **
void minute_needle(int m,int s){
    float angle=-90;
    float sx,sy;
    setcolor(0);
    sx=cx+M_N_L*cos((angle+m*6-6)*M_PI/180);
    sy=cy+M_N_L*sin((angle+m*6-6)*M_PI/180);
    line(cx,cy,sx,sy);
    setcolor(M_N_C);
    sx=cx+M_N_L*cos((angle+m*6/*+(s*6/60)*/)*M_PI/180);
    sy=cy+M_N_L*sin((angle+m*6/*+(s*6/60)*/)*M_PI/180);
    line(cx,cy,sx,sy);
}

//** Function to draw Hour needle. **
void hour_needle(int h,int m,int s){
    float angle=-90;
    float sx,sy;
    setcolor(0);
    sx=cx+H_N_L*cos((angle+h*30-(m*30/60))*M_PI/180);
    sy=cy+H_N_L*sin((angle+h*30-(m*30/60))*M_PI/180);
    line(cx,cy,sx,sy);
    setcolor(H_N_C);
    sx=cx+H_N_L*cos((angle+h*30+(m*30/60))*M_PI/180);
    sy=cy+H_N_L*sin((angle+h*30+(m*30/60))*M_PI/180);
    line(cx,cy,sx,sy);
}


