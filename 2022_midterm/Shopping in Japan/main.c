#include <stdio.h>
#include <math.h>
int main() {
    double shopping;
    double dollar_2019;
    double dollar_2022;
    double temp;

    scanf("%lf",&shopping);
    dollar_2019 = shopping;
    dollar_2022 = shopping;
    //2019
    if(dollar_2019>=5000){
        dollar_2019 = dollar_2019*0.2966;
        dollar_2019 = lround(dollar_2019);
    }else{
        dollar_2019 = dollar_2019*(1.08)*0.2966;
        dollar_2019 = lround(dollar_2019);
     //   printf("%lf ",dollar_2019);
    }
    //2022
    if(dollar_2022>=5000){
        dollar_2022 = dollar_2022*0.2178;
        dollar_2022 = lround(dollar_2022);
    }else{
        dollar_2022 = dollar_2022*(1.1)*0.2178;
        dollar_2022 = lround(dollar_2022);
      //  printf("%lf",dollar_2022);
    }
    temp = (dollar_2022-dollar_2019);
    if(temp<0){
        temp = -temp;
    }
    printf("%d",(int)temp);
    return 0;
}
