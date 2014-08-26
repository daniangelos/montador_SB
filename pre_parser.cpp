#include "pre_parser.hpp"

namespace pre_parser{
    int isPseudo(string string1){

        return 0;
    }

    int isLabel(string string1){
        int i;
        i = 0;

        while(string1[i] != '\0'){
            if(string1[i] == ':' && string1[i+1] == '\0'){
                return 1;
            }

            i++;
        }

        return 0;
    }

    int numOperandos(string instrucao){
        if(stringCompareI(instrucao,"COPY")){
            return 2;

        }else{
            if(stringCompareI(instrucao,"STOP")){
                return 0;
            }
            else{
                if(isInstruction(instrucao)){
                    return 1;

                }
                else{
                    return -1;

                }
            }
        }
    }

    int isOperando(string string1){
        if((string1[0] == 'N' || string1[0] == 'n') && !pre_parser::isLabel(string1)){
            return 1;

        }else{
            return 0;
        }
    }


    vector<string> getBasicInstFromPseudo(vector<string> pseudo){

        return pseudo;
    }

    //1 - upper || 2 - lower || 3 - nao caracter
    int isChar(char c){
        int caracter;
        caracter = (int)c;

        if(caracter >= 65 && caracter <= 90){
            return 1;
        }
        else{
            if(caracter >= 97 && caracter <= 122){
                return -1;

            }
            else{
                return 0;
            }
        }
    }

    int isNum(char c){
        int caracter;
        caracter = (int)c;
        if(caracter >= 48 && caracter <= 57){
            return 1;
        }
        else{
            return 0;
        }
    }

    int letraCompare(char c, char d){
        int atoic = (int)c;
        int atoid = (int)d;

        if(isChar(c) == 1){
            atoic = atoic + 32;
        }
        if(isChar(d) == 1){
            atoid = atoid + 32;
        }

        return (atoid == atoic);
    }

    int stringCompareI(string str1, string str2){
        int i = 0;

        if(str1.size() == str2.size()){
            while(str1[i] != '\0'){
                if(!letraCompare(str1[i],str2[i])){
                    return 0;
                }

                i++;
            }
        }
        else{
            return 0;
        }

        return 1;
    }


    int isDiretiva(string string1){
        string section("section");
        string equ("equ");
        string if_string("if");
        string space("space");
        string const_string("const");

        if(stringCompareI(string1, section)){
            return 1;
        }
        if(stringCompareI(string1, equ)){
            return 1;
        }
        if(stringCompareI(string1, if_string)){
            return 1;
        }
        if(stringCompareI(string1, space)){
            return 1;
        }
        if(stringCompareI(string1, const_string)){
            return 1;
        }
        return 0;
    }

    int isInstruction(string string1){


        if(stringCompareI(string1, "ADD")){
            return 1;
        }
        if(stringCompareI(string1, "SUB")){
            return 1;
        }
        if(stringCompareI(string1, "MULT")){
            return 1;
        }
        if(stringCompareI(string1, "DIV")){
            return 1;
        }
        if(stringCompareI(string1, "JMP")){
            return 1;
        }
        //mais
        if(stringCompareI(string1, "JMPN")){
            return 1;
        }
        if(stringCompareI(string1, "JMPP")){
            return 1;
        }
        if(stringCompareI(string1, "JMPZ")){
            return 1;
        }
        if(stringCompareI(string1, "COPY")){
            return 1;
        }
        if(stringCompareI(string1, "LOAD")){
            return 1;
        }
        //mais
        if(stringCompareI(string1, "STORE")){
            return 1;
        }
        if(stringCompareI(string1, "INPUT")){
            return 1;
        }
        if(stringCompareI(string1, "OUTPUT")){
            return 1;
        }
        if(stringCompareI(string1, "STOP")){
            return 1;
        }

        return 0;
    }

    void verificarMap(map<string,int> mymap){
        // show content:
        for (map<string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it){
            std::cout << it->first << " => " << it->second << '\n';
        }


    }


     void verificarMapString(map<string,string> mymap){
        // show content:
        for (map<string,string>::iterator it=mymap.begin(); it!=mymap.end(); ++it){
            std::cout << it->first << " => " << it->second << '\n';
        }


    }


    void verificarVector(vector<vector<string> > vetorStrings){
        int i;
        int j;

        for(i=0;i<vetorStrings.size();i++){
            for(j=0;j<vetorStrings[i].size();j++){

                cout << vetorStrings[i][j] << " ";
            }
            cout << endl;
        }


    }


    void gerarPreProcessado(vector<vector<string> > vetorStrings,char* arquivoPre){
        int i;
        int j;
        ofstream arquivoSaida(arquivoPre);


        for(i=0;i<vetorStrings.size();i++){
            for(j=0;j<vetorStrings[i].size();j++){
                arquivoSaida << vetorStrings[i][j];
                if(j+1<vetorStrings[i].size()){
                    arquivoSaida << " ";
                }
            }
            arquivoSaida << endl;
        }

        arquivoSaida.close();




    }


};
