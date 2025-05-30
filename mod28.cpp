#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << (x) << endl;
int main() {
    string str;
    cout << "INGRESAR EL MENSAJE: "<<endl;
    cin >> ws; // Example input: DZEAE JB
    getline(cin, str);
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    map<char, int> decode;
    for (int i = 0; i < 14; ++i) {
        decode['A' + i] = i + 1; // 'A' is 1, 'B' is 2, up to N 14
    }

    decode[' '] = 0;
    decode['~'] = 15;
    
    
    for (int i = 14; i < 28; ++i) {
        decode['A' + i] = i + 2; // from mN 14 to z 27
    }

    for (char w : str) {
        /*
        if (decode.find(c) != decode.end()) {
            cout << "Character: " << c << ", Value: " << decode[c] << endl;
        } else {
            cout << "Character: " << c << " is not in the map." << endl;
        }
        */
        cout<<decode[w]<<endl;

    }
    map<int,int> invdet={
        {1,1},
        {3,19},
        {5,17},
        {9,25},
        {11,23},
        {13,13},
        {15,15},
        {27,27}

    };

    cout<<"INGRESAR LA MATRIZ LLAVE 2x2"<<endl;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<"MATRIZ LLAVE: "<<endl;
    cout<<endl;
    vector<int>matriz;
    
    matriz.push_back(d);
    matriz.push_back(-b);
    matriz.push_back(-c);
    matriz.push_back(a);
    cout<<a<<" "<<b<<endl<<c<<" "<<d<<endl;
    cout<<endl;
    int det=a*d-b*c;
    cout << "DETERMINANTE:"<<endl;
    cout<<det<<endl;
    /*
    cout << "INGRESAR LA DETERMINANTE"<<endl;
    int det; cin>>det;
    */
    int invertido;
    
    if (invdet.find(det) != invdet.end()) {
        cout << "El valor correspondiente es: " << invdet[det] << endl;
        invertido=invdet[det];
    } else {
        for(auto& nice: invdet){
            if(nice.second==det){
                invertido=nice.first;
                 cout << "El valor correspondiente es: " << nice.first << endl;
                 }
            //else{cout << "Valor invalido"<< endl;}
        }
    }
    /*
    cout << "INGRESAR LOS NUMEROS DE LA  PARA MOD28 "<<endl;
    cout << "SE ASUME UNA MATRIZ ADJ DE IZQ A DERECHA 2*2"<<endl;
    */
    vector<int>matadj;
    float g;
    for(int i=0;i<4;i++){
        g=float(matriz[i]);
        //cin>>g;
        g=g*invertido;
        if(g<0){
            int res;
            int temp=g;
            g=g/28.0;
            //debug(g)
            int ent=int(temp)/28;
            //debug(ent)
            ent = abs(ent)+1;
            //debug(ent)
            res = int((g+ent)*28);
            matadj.push_back(res);
            //debug(res)

        } else{
        //g es positivo
        int v = int(g);
        v=v%28;
        matadj.push_back(v);
    }
    }
    cout<<"MATRIZ INVERSA"<<endl;
    cout<<endl;
    for(int y=0;y<4;y++){
        cout<<matadj[y]<<" ";
        if(y==1){cout<<endl;} 
    }
    cout<<endl;
    cout<<endl;


    cout << "INGRESAR LOS NUMEROS PRODUCTO DE A^-1*E A CODIFICAR A MOD28: "<<endl;
    int n;
    vector<int>xd;
    while(cin>>n){
        int a=n%28;
        cout<<n<<"="<<a<<endl;
        xd.push_back(a);
        
    }
    cout << "MENSAJE DECODIFICADO"<<endl;
    cout<<endl;
    map<int, char> reverseDecode;
    for (auto& pair : decode) {
        reverseDecode[pair.second] = pair.first; // Reverse the decode map
    }

    for (int num : xd) {
        if (reverseDecode.find(num) != reverseDecode.end()) {
            cout << reverseDecode[num];
        } else {
            cout << "?"; // Placeholder for unmapped numbers
        }
    }
    return 0;
}