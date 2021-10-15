#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "dominios.h"
#include "entidades.h"

using namespace std;

vector<Participante> participanteVector = {};

fstream banco;

void adicionarParticipante() {
    Matricula matricula;
    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;


    Participante participante;

    bool found = false;


    char inputMatricula[80], inputNome[80], inputSobrenome[80], inputEmail[80], inputTelefone[80], inputSenha[80], inputCargo[80];
    cin.ignore();
    cout << "Insira seus dados" << endl;
    cout << "====================================" << endl;
    cout << "Matrícula: ";
    cin.getline(inputMatricula,sizeof(inputMatricula));
    try{
        matricula.setValor(string(inputMatricula));
    }
    catch(invalid_argument &exp) {
        cout << "Matricula precisa ter 5 dígitos distintos" << endl;
        return;
    }

    participante.setMatricula(matricula);

    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
        if(participanteVector[i].getMatricula().getValor() == participante.getMatricula().getValor()) {
            found = true;
            cout << "Matrícula já cadastrada" << endl;
            return;
        }
    }



    cout << "Nome: ";
    cin.getline(inputNome,sizeof(inputNome));
    try{
        nome.setValor(string(inputNome));
    }
    catch(invalid_argument &exp){
        cout << "Cada palavra do nome deve começar com letra maiúscula e ter entre 5 e 20 caracteres" << endl;
        return;
    }
    cout << "Sobrenome: ";
    cin.getline(inputSobrenome,sizeof(inputSobrenome));
    try{
        sobrenome.setValor(string(inputSobrenome));
    }
    catch(invalid_argument &exp){
        cout << "Cada palavra do sobrenome deve começar com letra maiúscula e ter entre 5 e 20 caracteres" << endl;
        return;
    }
    cout << "Email: ";
    cin.getline(inputEmail,sizeof(inputEmail));
    try{
        email.setValor(string(inputEmail));
    }
    catch(invalid_argument &exp){
        cout << "Email precisa conter @" << endl;
        return;
    }
    cout << "Telefone: ";
    cin.getline(inputTelefone,sizeof(inputTelefone));
    try{
        telefone.setValor(string(inputTelefone));
    }
    catch(invalid_argument &exp){
        cout << "O DDD precisa ser válido e o telefone deve estar no formato (99)-999999999" << endl;
        return;
    }
    cout << "Senha: ";
    cin.getline(inputSenha,sizeof(inputSenha));
    try{
        senha.setValor(string(inputSenha));
    }
    catch(invalid_argument &exp){
        cout << "Senha precisa conter 8 caracteres distintos tendo pelo menos uma letra, um número e um caractere especial" << endl;
        return;
    }
    cout << "Cargo: ";
    cin.getline(inputCargo,sizeof(inputCargo));
    try{
        cargo.setValor(string(inputCargo));
    }
    catch(invalid_argument &exp){
        cout << "Escolha um cargo válido como ator, figurinista ou iluminador" << endl;
        return;
    }


    participante.setNome(nome);
    participante.setSobrenome(sobrenome);
    participante.setEmail(email);
    participante.setTelefone(telefone);
    participante.setSenha(senha);
    participante.setCargo(cargo);
    if(!found) {participanteVector.push_back(participante);/*int j = participanteVector.size() - 1;
    banco.open("banco.txt", ios::out);
        if(banco.is_open()) {
            banco << participante.getMatricula().getValor();
            banco << participante.getNome().getValor();
            banco << participante.getSobrenome().getValor();
            banco << participante.getEmail().getValor();
            banco << participante.getTelefone().getValor();
            banco << participante.getSenha().getValor();
            banco << participante.getCargo().getValor();
        }
        banco.close();*/
    }
   cout << "====================================" << endl;
}

//Função para teste
void listarParticipante() {
    bool found = false;
    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
        cout << participanteVector[i].getMatricula().getValor() << endl;
            found = true;
    }
    if(!found) cout << "No participants" << endl;
}


//Função para tests
void visualizarDadosPessoais(string inputMatricula) {
    string nome, sobrenome, email, telefone, senha, cargo;
    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
       if(participanteVector[i].getMatricula().getValor() == inputMatricula) {
            nome = participanteVector[i].getNome().getValor();
            sobrenome = participanteVector[i].getSobrenome().getValor();
            email = participanteVector[i].getEmail().getValor();
            telefone = participanteVector[i].getTelefone().getValor();
            senha = participanteVector[i].getSenha().getValor();
            cargo = participanteVector[i].getCargo().getValor();
            break;
        }
    }
    cout << "====================================" << endl;
    cout << "Matrícula: " << inputMatricula << endl;
    cout << "Nome: " << nome << endl;
    cout << "Sobrenome: " << sobrenome << endl;
    cout << "Email: " << email << endl;
    cout << "Telefone: " << telefone << endl;
    cout << "Senha: " << senha << endl;
    cout << "Cargo: " << cargo << endl;
    cout << "====================================" << endl;
}

void editarDadosPessoais(string inputMatricula) {
    Matricula matricula;
    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;

    matricula.setValor(string(inputMatricula));

    char inputNome[80], inputSobrenome[80], inputEmail[80], inputTelefone[80], inputSenha[80], inputCargo[80];
    cin.ignore();
    cout << "Insira seus dados atualizados" << endl;
    cout << "====================================" << endl;
    cout << "Nome: ";
    cin.getline(inputNome,sizeof(inputNome));
    try{
        nome.setValor(string(inputNome));
    }
    catch(invalid_argument &exp){
        cout << "Cada palavra do nome deve começar com letra maiúscula e ter entre 5 e 20 caracteres" << endl;
        return;
    }
    cout << "Sobrenome: ";
    cin.getline(inputSobrenome,sizeof(inputSobrenome));
    try{
        sobrenome.setValor(string(inputSobrenome));
    }
    catch(invalid_argument &exp){
        cout << "Cada palavra do sobrenome deve começar com letra maiúscula e ter entre 5 e 20 caracteres" << endl;
        return;
    }
    cout << "Email: ";
    cin.getline(inputEmail,sizeof(inputEmail));
    try{
        email.setValor(string(inputEmail));
    }
    catch(invalid_argument &exp){
        cout << "Email precisa conter @" << endl;
        return;
    }
    cout << "Telefone: ";
    cin.getline(inputTelefone,sizeof(inputTelefone));
    try{
        telefone.setValor(string(inputTelefone));
    }
    catch(invalid_argument &exp){
        cout << "O DDD precisa ser válido e o telefone deve estar no formato (99)-999999999" << endl;
        return;
    }
    cout << "Senha: ";
    cin.getline(inputSenha,sizeof(inputSenha));
    try{
        senha.setValor(string(inputSenha));
    }
    catch(invalid_argument &exp){
        cout << "Senha precisa conter 8 caracteres distintos tendo pelo menos uma letra, um número e um caractere especial" << endl;
        return;
    }
    cout << "Cargo: ";
    cin.getline(inputCargo,sizeof(inputCargo));
    try{
        cargo.setValor(string(inputCargo));
    }
    catch(invalid_argument &exp){
        cout << "Escolha um cargo válido como ator, figurinista ou iluminador" << endl;
        return;
    }

    bool found = false;

    /*Participante participante;
    participante.setMatricula(matricula);*/
    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
        if(participanteVector[i].getMatricula().getValor() == inputMatricula) {
            found = true;
            participanteVector[i].setNome(nome);
            participanteVector[i].setSobrenome(sobrenome);
            participanteVector[i].setEmail(email);
            participanteVector[i].setTelefone(telefone);
            participanteVector[i].setSenha(senha);
            participanteVector[i].setCargo(cargo);
            cout << "Informações atualizadas com sucesso" << endl;
            break;
        }
    }
   cout << "====================================" << endl;
}

void excluirParticipante(string inputMatricula) {
    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
        if(participanteVector[i].getMatricula().getValor() == inputMatricula) {
            participanteVector.erase(participanteVector.begin() + i);
            cout << "Cadastro excluído com sucesso" << endl;
            break;
        }
    }
}

void criarPeca(string inputMatricula) {
    /*Codigo codigo;
    Nome nome;
    Tipo tipo;
    Classificação classificação;
    char inputCodigo[80], inputNome[80], inputTipo[80], inputClassificacao[80];
    cin.ignore();
    cout << "Insira os dados da peça" << endl;
    cout << "====================================" << endl;
    cout << "Codigo: ";
    cin.getline(inputCodigo,sizeof(inputCodigo));
    try{
        codigo.setValor(string(inputCodigo));
    }
    catch(invalid_argument &exp){
        cout << "Codigo no formato LLDDD no qual L é letra maiúscula e D é dígito" << endl;
        return;
    }
    cout << "Nome: ";
    cin.getline(inputNome,sizeof(inputNome));
    try{
        nome.setValor(string(inputNome));
    }
    catch(invalid_argument &exp){
        cout << "Cada palavra do nome deve começar com letra maiúscula e ter entre 5 e 20 caracteres" << endl;
        return;
    }
    cout << "Tipo: ";
    cin.getline(inputTipo,sizeof(inputTipo));
    try{
        tipo.setValor(string(inputTipo));
    }
    catch(invalid_argument &exp){
        cout << "Insira um tipo válido como auto, drama ou farsa" << endl;
        return;
    }
    cout << "Classificação: ";
    cin.getline(inputClassificacao,sizeof(inputClassificacao));
    try{
        Classificacao.setValor(string(inputClassificacao));
    }
    catch(invalid_argument &exp){
        cout << "Insira um tipo válido como livre, 10 ou 12" << endl;
        return;
    }

    bool found = false;

    Peca peca;
    peca.setCodigo(codigo);
    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);
    for(int i = 0; (unsigned)i < pecaVector.size(); i++){
        if(participanteVector[i].getMatricula().getValor() == participante.getMatricula().getValor()) {
            found = true;
            cout << "Matrícula já cadastrada" << endl;
            break;
        }
    }
    if(!found) {participanteVector.push_back(participante);/*int j = participanteVector.size() - 1;
    banco.open("banco.txt", ios::out);
        if(banco.is_open()) {
            banco << participante.getMatricula().getValor();
            banco << participante.getNome().getValor();
            banco << participante.getSobrenome().getValor();
            banco << participante.getEmail().getValor();
            banco << participante.getTelefone().getValor();
            banco << participante.getSenha().getValor();
            banco << participante.getCargo().getValor();
        }
        banco.close();
    }
   cout << "====================================" << endl;*/
}

void procurarPeca() {
    cout << "oi" << endl;
}

void editarPeca() {
    cout << "oi" << endl;
}

void excluirPeca() {
    cout << "oi" << endl;
}

void criarSessao() {
    cout << "oi" << endl;
}

void procurarSessao() {
    cout << "oi" << endl;
}

void editarSessao() {
    cout << "oi" << endl;
}

void excluirSessao() {
    cout << "oi" << endl;
}

void criarSala() {
    cout << "oi" << endl;
}

void procurarSala() {
    cout << "oi" << endl;
}

void editarSala() {
    cout << "oi" << endl;
}

void excluirSala() {
    cout << "oi" << endl;
}


void participanteAutenticado(string inputMatricula){
    int option;
    do {
        cout << "Sua matrícula é: " << inputMatricula << endl;
        cout << "1 - Visualizar dados pessoais" << endl;
        cout << "2 - Editar dados pessoais" << endl;
        cout << "3 - Excluir cadastro no sistema" << endl;
        cout << "4 - Criar peça" << endl;
        cout << "5 - Procurar peça" << endl;
        cout << "6 - Editar peça" << endl;
        cout << "7 - Excluir peça" << endl;
        cout << "8 - Criar sessão" << endl;
        cout << "9 - Procurar sessão" << endl;
        cout << "10 - Editar sessão" << endl;
        cout << "11 - Excluir sessão" << endl;
        cout << "12 - Criar sala" << endl;
        cout << "13 - Procurar sala" << endl;
        cout << "14 - Editar sala" << endl;
        cout << "15 - Excluir sala" << endl;
        cout << "16 - Retorna à tela inicial" << endl;
        cout << "Selecione a opção >> ";

        cin >> option;

        switch(option) {
            case 1: visualizarDadosPessoais(inputMatricula);
                    break;
            case 2: editarDadosPessoais(inputMatricula);
                    break;
            case 3: excluirParticipante(inputMatricula);
                    break;
            case 4: criarPeca(inputMatricula);
                    break;
            case 5: procurarPeca();
                    break;
            case 6: editarPeca();
                    break;
            case 7: excluirPeca();
                    break;
            case 8: criarSessao();
                    break;
            case 9: procurarSessao();
                    break;
            case 10: editarSessao();
                    break;
            case 11: excluirSessao();
                    break;
            case 12: criarSala();
                    break;
            case 13: procurarSala();
                    break;
            case 14: editarSala();
                    break;
            case 15: excluirSala();
                    break;
        }
    } while(option != 16 && option != 3);
}

void autenticarParticipante() {
    Matricula matricula;
    Senha senha;
    char inputMatricula[80], inputSenha[80];
    cin.ignore();
    cout << "Insira seus dados" << endl;
    cout << "====================================" << endl;
    cout << "Matrícula: ";
    cin.getline(inputMatricula,sizeof(inputMatricula));
    try{
        matricula.setValor(string(inputMatricula));
    }
    catch(invalid_argument &exp){
        cout << "Matricula precisa ter 5 dígitos distintos" << endl;
        return;
    }
    cout << "Senha: ";
    cin.getline(inputSenha,sizeof(inputSenha));
    try{
        senha.setValor(string(inputSenha));
    }
    catch(invalid_argument &exp){
        cout << "Senha precisa conter 8 caracteres distintos tendo pelo menos uma letra, um número e um caractere especial" << endl;
        return;
    }

    Participante participante;
    participante.setMatricula(matricula);
    participante.setSenha(senha);

    bool foundMatricula = false;
    bool foundSenha = false;

    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
       if(participanteVector[i].getMatricula().getValor() == participante.getMatricula().getValor()) {
           foundMatricula = true;
            if(participanteVector[i].getSenha().getValor() == participante.getSenha().getValor()) {
                foundSenha = true;
            }
        }
    }
    if(foundSenha) participanteAutenticado(inputMatricula);
    else if(foundMatricula) {
        cout << "Senha incorreta!" << endl;
        return;
    }
    else {
        cout << "Participante não cadastrado!" << endl;
        return;
    }
}

void listarPeca() {
    cout << "oi" << endl;
}

void listarSessao() {
    cout << "oi" << endl;
}

void listarSala() {
    cout << "oi" << endl;
}

int main() {
        Matricula matricula;
    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;
    /*banco.open("banco.txt", ios::in);
if(banco.is_open()) {
    string line;
    int i = 0;
    while(getline(banco, line)) {
        Matricula matricula;
        matricula.setValor(line);
        participanteVector[i].setMatricula(matricula);
        Nome nome;
        matricula.setValor(line);
        participanteVector[i].setMatricula(matricula);
                Matricula matricula;
        matricula.setValor(line);
        participanteVector[i].setMatricula(matricula);
                Matricula matricula;
        matricula.setValor(line);
        participanteVector[i].setMatricula(matricula);
                Matricula matricula;
        matricula.setValor(line);
        participanteVector[i].setMatricula(matricula);
                Matricula matricula;
        matricula.setValor(line);
        participanteVector[i].setMatricula(matricula);
                Matricula matricula;
        matricula.setValor(line);
        participanteVector[i].setMatricula(matricula);
        i++;
    }
    banco.close();
}*/

    int option;

    do {
        cout << "1 - Acessar sistema" << endl;
        cout << "2 - Realizar cadastro" << endl;
        cout << "3 - Listar peças" << endl;
        cout << "4 - Listar sessões" << endl;
        cout << "5 - Listar salas" << endl;
        cout << "6 - Sair do sistema" << endl;
                cout << "7 - Listar participantes" << endl;
        cout << "Selecione a opção >> ";

        cin >> option;

        switch(option) {
            case 1: autenticarParticipante();
                    break;
            case 2: adicionarParticipante();
                    break;
            case 3: listarPeca();
                    break;
            case 4: listarSessao();
                    break;
            case 5: listarSala();
                    break;
                    case 7: listarParticipante();
                    break;
        }
    } while(option != 6);
}
