
#include <bits/stdc++.h> 
using namespace std;

void letxt(string& s)
{
    ifstream arq("arqTexto.txt");

    if(arq.is_open())
    {
        
        string str;
        int count = 1;

        while(getline(arq, str))
        {
            count++;
        }

        s = str;
        
    }
    else
        cerr << "ERRO: O arquivo nao pode ser aberto!" << endl;
}
vector<int>codificador(string entrada)
{
    unordered_map<string,int> dicionarioTabelaACII;

    for(int i=0;i<=255;i++)
    {
        string s ="";
        s += char(i);
        dicionarioTabelaACII[s] = i;
    }

    string st ="",c ="";
    st+=entrada[0];
    int codigo = 256;
    vector<int>saida;

    for(int i=0;i<entrada.length();i++)
    {
        if(i!=entrada.length()-1)
            c+=entrada[i+1];
        if(dicionarioTabelaACII.find(st+c)!=dicionarioTabelaACII.end())
        {
            st = st + c;
        }else{

            saida.push_back(dicionarioTabelaACII[st]);
            dicionarioTabelaACII[st+c]=codigo;
            codigo++;
            st=c;

        }
        c="";
    }
    saida.push_back(dicionarioTabelaACII[st]);
    return saida;
}
  
void decodificado(vector<int> entrada)
{
    unordered_map<int,string> dicionarioTabelaACII;

    for(int i=0;i<=255;i++)
    {
        string s ="";
        s += char(i);
        dicionarioTabelaACII[i] = s;
    }

    int dec = entrada[0],n;
    string s = dicionarioTabelaACII[dec];
    string c = "";
    c += s[0];
    cout<<s;
    int contador = 256;

    for(int i=0;i<entrada.size()-1;i++)
    {
        n = entrada[i+1];
        if(dicionarioTabelaACII.find(n) == dicionarioTabelaACII.end())
        {   
            s = s + c;
            s = dicionarioTabelaACII[dec];
            

        }else
        {
            s = dicionarioTabelaACII[n];
        }
        cout<<s;
        c="";
        c+=s[0];
        dicionarioTabelaACII[contador] = dicionarioTabelaACII[dec] + c;
        contador++;
        dec = n;

    }

}
int main()
{   
    string str;
    letxt(str);
    vector<int> codigo = codificador(str);

    cout<<"Codificador"<<endl;
    for(int i=0;i<codigo.size();i++)
    {
        cout<<codigo[i]<<" ";
    }
    cout<<endl;
    cout<<"Decodificador"<<endl;
    decodificado(codigo);
    return 0;
}
