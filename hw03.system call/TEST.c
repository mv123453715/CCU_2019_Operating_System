#define MAXLEN  1024
int main(void)
{
    int ret;
   // char key[17];
    char *p;

    p = (char*)malloc(MAXLEN*(sizeof(char*)));	//�ӽФ@���O����A�s��Ū�����
    memset(p,0,MAXLEN);

    printf("�п�J�@��r���G\n");

    ret = read(0,p,MAXLEN);

    printf("read �禡�N�i�H�����qcommand line Ū����ƶܡH�դ@��read��S�I\n");
    printf("�U�����w�q�O�����ƿ�X�C�C�C\n");

    for(int i =0; p[i]!='\n';i++)
    {
        printf("key[%d] = %c\n",i,p[i]);
    }
}
