// ======================== Information ============================
// 임베디드에서 사용할 것이기때문에 숫자만 출력하도록 만들었다.
// unsigned char, int, long 의 범위에 속하는 숫자를 입력했을 때
// 이를 문자로 출력되도록 하는 함수 fun을 만들었다.

// printf로 저장된 데이터를 확인하기위하여 헤더파일을 사용
#include<stdio.h>

// ======================= Type definition ==========================
typedef unsigned char	tU08; // 0 ~ 255
typedef unsigned int	tU16; // 0 ~ 65,535
typedef unsigned long	tU32; // 0 ~ 4,294,967,295

// ======================= Valuable definition ======================
tU08 argindex=0;               // 인자의 인덱스
tU08 dataindex=0;              // 데이터 인덱스
tU08 format[100]={0};         // raw 데이터를 저장할 버퍼
tU08 databuffer[100]={0};     // 가공후 데이터를 저장할 버퍼
void* argbuffer[10]={0};      // 10개의 인자값의 주소를 저장할 버퍼

// ========================== Function ==============================

// tU08을 문자로 변환
void fun_1toC(){
    tU08 h=*(tU08*)argbuffer[argindex]/100 + 0x30; // 아스키코드로 나타내기위해 0x30을 더하여 숫자로 나타낸다.
    tU08 t=(*(tU08*)argbuffer[argindex]%100)/10 + 0x30;
    tU08 o=(*(tU08*)argbuffer[argindex]%100)%10 + 0x30;

    // 처음숫자가 0이 아니면 아래 숫자 다 출력하기
    if(h!=0x30){            // h가 0이 아닐경우 h,t,o를 다 저장한다. 0으로 하면 null로 들어가기 때문에 문자인 0x30으로 줘야한다.
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;
    }
    if(t!=0x30){            // h가 0일 경우 t,o를 저장한다.
        databuffer[dataindex++] = t;
    }
    databuffer[dataindex++] = o; // h,t 가 0일경우 o만 저장한다.

    argindex++; // 형을 변환했으면 다음 arg의 값을 받아오기위해 값을 하나 증가시킨다.
}

// tU16을 문자로 변환
void fun_2toC(){
    tU16 tt=*(tU16*)argbuffer[argindex]/10000 + 0x30;
    tU16 ot=(*(tU16*)argbuffer[argindex]%10000)/1000 + 0x30;
    tU16 h=((*(tU16*)argbuffer[argindex]%10000)%1000)/100 + 0x30;
    tU16 t=(((*(tU16*)argbuffer[argindex]%10000)%1000)%100)/10 + 0x30;
    tU16 o=(((*(tU16*)argbuffer[argindex]%10000)%1000)%100)%10 + 0x30;

    if(tt!=0x30){
        databuffer[dataindex++] = tt;
        databuffer[dataindex++] = ot;
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;
    }
    if(ot!=0x30){
        databuffer[dataindex++] = ot;
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;
    }
    if(h!=0x30){            // h가 0이 아닐경우 h,t,o를 다 저장한다. 0으로 하면 null로 들어가기 때문에 문자인 0x30으로 줘야한다.
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;
    }
    if(t){            // h가 0일 경우 t,o를 저장한다.
        databuffer[dataindex++] = t;
    }
    databuffer[dataindex++] = o;

    argindex++;
}

// tU32를 문자로 변환
void fun_4toC(){
    tU32 ob=*(tU32*)argbuffer[argindex]/1000000000 + 0x30;
    tU32 hm=(*(tU32*)argbuffer[argindex]%1000000000)/100000000 + 0x30;
    tU32 tm=((*(tU32*)argbuffer[argindex]%1000000000)%100000000)/10000000 + 0x30;
    tU32 om=(((*(tU32*)argbuffer[argindex]%1000000000)%1000000000)%10000000)/1000000 + 0x30;
    tU32 ht=((((*(tU32*)argbuffer[argindex]%1000000000)%1000000000)%10000000)%1000000)/100000 + 0x30;
    tU32 tt=(((((*(tU32*)argbuffer[argindex]%1000000000)%1000000000)%10000000)%1000000)%100000)/10000 + 0x30;
    tU32 ot=((((((*(tU32*)argbuffer[argindex]%1000000000)%1000000000)%10000000)%1000000)%100000)%10000)/1000 + 0x30;
    tU32 h=(((((((*(tU32*)argbuffer[argindex]%1000000000)%1000000000)%10000000)%1000000)%100000)%10000)%1000)/100 + 0x30;
    tU32 t=((((((((*(tU32*)argbuffer[argindex]%1000000000)%1000000000)%10000000)%1000000)%100000)%10000)%1000)%100)/10 + 0x30;
    tU32 o=((((((((*(tU32*)argbuffer[argindex]%1000000000)%1000000000)%10000000)%1000000)%100000)%10000)%1000)%100)%10 + 0x30;


    if(ob!=0x30){
        databuffer[dataindex++] = ob;
        databuffer[dataindex++] = hm;
        databuffer[dataindex++] = tm;
        databuffer[dataindex++] = om;
        databuffer[dataindex++] = ht;
        databuffer[dataindex++] = tt;
        databuffer[dataindex++] = ot;
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;
    }
    if(hm!=0x30){
        databuffer[dataindex++] = hm;
        databuffer[dataindex++] = tm;
        databuffer[dataindex++] = om;
        databuffer[dataindex++] = ht;
        databuffer[dataindex++] = tt;
        databuffer[dataindex++] = ot;
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;
    }
    if(tm!=0x30){
        databuffer[dataindex++] = tm;
        databuffer[dataindex++] = om;
        databuffer[dataindex++] = ht;
        databuffer[dataindex++] = tt;
        databuffer[dataindex++] = ot;
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;
    }
    if(om!=0x30){
        databuffer[dataindex++] = om;
        databuffer[dataindex++] = ht;
        databuffer[dataindex++] = tt;
        databuffer[dataindex++] = ot;
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;
    }
    if(ht!=0x30){
        databuffer[dataindex++] = ht;
        databuffer[dataindex++] = tt;
        databuffer[dataindex++] = ot;
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;
    }
    if(tt!=0x30){
        databuffer[dataindex++] = tt;
        databuffer[dataindex++] = ot;
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;
    }
    if(ot!=0x30){
        databuffer[dataindex++] = ot;
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;

    }
    if(h!=0x30){
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;
    }
    if(t!=0x30){
        databuffer[dataindex++] = t;
    }
    databuffer[dataindex++] = o;

    argindex++;
}

// 받아온 인자의 형 변환하기
void fun_typeto(){
    tU08 index=0;
    while(format[index]!=0){    // 입력한 데이터가 null이 되기 전까지 수행
        if(format[index]=='%'){ // %가 발견되면
            switch(format[++index]){ // %뒤에 값이 1,2,4인가에 따라 형변환을 한다.
            case '1': // 1일 경우 char형을 문자로 변환
                fun_1toC();
                break;
            case '2': // 2일 경우 int형을 문자로 변환
                fun_2toC();
                break;
            case '4': // 4일 경우 long형을 문자로 변환
                fun_4toC();
                break;
            default:
                break;
            }
        }
        else{
            databuffer[dataindex++]=format[index]; // %가 아닌 데이터들은 databuffer에 그대로 저장
        }
        index++; // format내의 다음 값을 받아온다.
    }
}

// printf의 기능을 하는 함수
tU08 fun(tU08* input_format, void* arg1, void*arg2, void* arg3, void* arg4, void* arg5, void* arg6, void* arg7, void* arg8, void* arg9, void* arg10){
    argbuffer[0]=arg1; // argbuffer에 하나씩 arg를 저장한다.
    argbuffer[1]=arg2; // 값이 little endian stack으로 저장된다.
    argbuffer[2]=arg3;
    argbuffer[3]=arg4;
    argbuffer[4]=arg5;
    argbuffer[5]=arg6;
    argbuffer[6]=arg7;
    argbuffer[7]=arg8;
    argbuffer[8]=arg9;
    argbuffer[9]=arg10;

    for(int i=0;i<100;i++){ // input_format으로 들어온 값들을 하나싹 format에 저장한다.
        format[i]=input_format[i];
    }

    fun_typeto();
    return databuffer; // 가공된 데이터를 출력한다.
}

// ================================ Main ============================
int main()
{
    tU08 a1=100;
    tU08 a2=101;
    tU08 a3=102;
    tU08 a4=103;

    tU16 b1=10000;
    tU16 b2=10001;
    tU16 b3=10002;

    tU32 c1=1000000000;
    tU32 c2=1000000001;
    tU32 c3=1000000002;

    fun("Hello %1 %1 %1 %1 %2 %2 %2 %4 %4 %4",&a1,&a2,&a3,&a4,&b1,&b2,&b3,&c1,&c2,&c3);

    // 데이터가 제대로 저장됐는지 printf로 확인하기
    //printf("%s",databuffer);
    return 0;
}


