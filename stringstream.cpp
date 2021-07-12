void stringtoint() { ///b is the array where ll are stored , s is the string
    getline(cin,s);
    stringstream ss(s);
    i=0;
    while(ss>>num)b[i++]=num;
}
