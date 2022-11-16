// ======================== Information ============================
// �Ӻ���忡�� ����� ���̱⶧���� ���ڸ� ����ϵ��� �������.
// unsigned char, int, long �� ������ ���ϴ� ���ڸ� �Է����� ��
// �̸� ���ڷ� ��µǵ��� �ϴ� �Լ� fun�� �������.

// printf�� ����� �����͸� Ȯ���ϱ����Ͽ� ��������� ���
#include<stdio.h>

// ======================= Type definition ==========================
typedef unsigned char	tU08; // 0 ~ 255
typedef unsigned int	tU16; // 0 ~ 65,535
typedef unsigned long	tU32; // 0 ~ 4,294,967,295

// ======================= Valuable definition ======================
tU08 argindex=0;               // ������ �ε���
tU08 dataindex=0;              // ������ �ε���
tU08 format[100]={0};         // raw �����͸� ������ ����
tU08 databuffer[100]={0};     // ������ �����͸� ������ ����
void* argbuffer[10]={0};      // 10���� ���ڰ��� �ּҸ� ������ ����

// ========================== Function ==============================

// tU08�� ���ڷ� ��ȯ
void fun_1toC(){
    tU08 h=*(tU08*)argbuffer[argindex]/100 + 0x30; // �ƽ�Ű�ڵ�� ��Ÿ�������� 0x30�� ���Ͽ� ���ڷ� ��Ÿ����.
    tU08 t=(*(tU08*)argbuffer[argindex]%100)/10 + 0x30;
    tU08 o=(*(tU08*)argbuffer[argindex]%100)%10 + 0x30;

    // ó�����ڰ� 0�� �ƴϸ� �Ʒ� ���� �� ����ϱ�
    if(h!=0x30){            // h�� 0�� �ƴҰ�� h,t,o�� �� �����Ѵ�. 0���� �ϸ� null�� ���� ������ ������ 0x30���� ����Ѵ�.
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;
    }
    if(t){            // h�� 0�� ��� t,o�� �����Ѵ�.
        databuffer[dataindex++] = t;
    }
    databuffer[dataindex++] = o; // h,t �� 0�ϰ�� o�� �����Ѵ�.

    argindex++; // ���� ��ȯ������ ���� arg�� ���� �޾ƿ������� ���� �ϳ� ������Ų��.
}

// tU16�� ���ڷ� ��ȯ
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
    if(h!=0x30){            // h�� 0�� �ƴҰ�� h,t,o�� �� �����Ѵ�. 0���� �ϸ� null�� ���� ������ ������ 0x30���� ����Ѵ�.
        databuffer[dataindex++] = h;
        databuffer[dataindex++] = t;
    }
    if(t){            // h�� 0�� ��� t,o�� �����Ѵ�.
        databuffer[dataindex++] = t;
    }
    databuffer[dataindex++] = o;

    argindex++;
}

// tU32�� ���ڷ� ��ȯ
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

// �޾ƿ� ������ �� ��ȯ�ϱ�
void fun_typeto(){
    tU08 index=0;
    while(format[index]!=0){    // �Է��� �����Ͱ� null�� �Ǳ� ������ ����
        if(format[index]=='%'){ // %�� �߰ߵǸ�
            switch(format[++index]){ // %�ڿ� ���� 1,2,4�ΰ��� ���� ����ȯ�� �Ѵ�.
            case '1': // 1�� ��� char���� ���ڷ� ��ȯ
                fun_1toC();
                break;
            case '2': // 2�� ��� int���� ���ڷ� ��ȯ
                fun_2toC();
                break;
            case '4': // 4�� ��� long���� ���ڷ� ��ȯ
                fun_4toC();
                break;
            default:
                break;
            }
        }
        else{
            databuffer[dataindex++]=format[index]; // %�� �ƴ� �����͵��� databuffer�� �״�� ����
        }
        index++; // format���� ���� ���� �޾ƿ´�.
    }
}

// printf�� ����� �ϴ� �Լ�
tU08 fun(tU08* input_format, void* arg1, void*arg2, void* arg3, void* arg4, void* arg5, void* arg6, void* arg7, void* arg8, void* arg9, void* arg10){
    argbuffer[0]=arg1; // argbuffer�� �ϳ��� arg�� �����Ѵ�.
    argbuffer[1]=arg2; // ���� little endian stack���� ����ȴ�.
    argbuffer[2]=arg3;
    argbuffer[3]=arg4;
    argbuffer[4]=arg5;
    argbuffer[5]=arg6;
    argbuffer[6]=arg7;
    argbuffer[7]=arg8;
    argbuffer[8]=arg9;
    argbuffer[9]=arg10;

    for(int i=0;i<100;i++){ // input_format���� ���� ������ �ϳ��� format�� �����Ѵ�.
        format[i]=input_format[i];
    }

    fun_typeto();
    return databuffer; // ������ �����͸� ����Ѵ�.
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

    // �����Ͱ� ����� ����ƴ��� printf�� Ȯ���ϱ�
    //printf("%s",databuffer);
    return 0;
}


