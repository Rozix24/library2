int wishes(float days, bool welkingmoon){
    if(welkingmoon==1){
        days = (days*(60+90))/160;
    }
    else{
        days = (days*60)/160;
    }
    return days;
}

int chance1(float days, int banners, bool welkingmoon, bool guaranteed, float wishes, int pity){ //a chance of getting a 5* event character
    float answer{0};

    days += 21*banners;  //how many days are there left until the end of the banners
    if(welkingmoon==1){  //how many wishes will u get during that time (comissions: 60 primogems, with or without welking moon:90 primogems)
        wishes = (days*(60+90))/160;
    }
    else{
        wishes = (days*60)/160;
    }
    wishes += pity; //how many wishes do u have, with the pity

    if(guaranteed==1){ //a chance of getting a 5* event character (90: guaranteed 5*. 180: guaranteed event 5*)
        answer = (wishes/90)*100;
    }
    else{
        answer = (wishes/180)*100;
    }
    return answer;
}

float chance2(float days, int banners, bool welkingmoon, bool guaranteed, float wishes, int pity){ //a chance of getting a 5* event character according to amount of wishes
    float answer{0};
    days += 21*banners;  //how many days are there left until the end of the banners
    if(welkingmoon==1){  //how many wishes will u get during that time (comissions: 60 primogems, with or without welking moon:90 primogems)
        wishes = (days*(60+90))/160;
    }
    else{
        wishes = (days*60)/160;
    }
    wishes += pity; //how many wishes do u have, with the pity

    if(guaranteed==1){ //a chance of getting a 5* event character (90: guaranteed 5*, 180: guaranteed event 5*, after 75: 20.627%, before 75: 0.6%-0.4%) according to pity
        if(wishes>=90){ answer = 100;}
        if(wishes>=75){ answer = 20.627;}
    }
    else{
        if(wishes>=180){ answer = 100;}
        if(wishes>165){ answer = 20.627;}
        if(wishes<=160) { answer = 0.6;}
    }
    return answer;
}
