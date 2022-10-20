#include <iostream>
#include "Restaurante.h"
#include "Cliente.h"
#include "Funcionario.h"
#include "Gerente.h"
#include "Item.h"
#include "ListaEspera.h"
#include "Pedido.h"

int main(){
    Item* itemum = new Item("Filé de Frango", "Acompanha: arroz,feijão,farofa,alface,tomate e cenoura", 17.9, 30.0, 1);
    Item* itemdois = new Item("Pernil Grelhado", "Acompanha: arroz,feijão,farofa,fritas,alface,tomate e cenoura", 17.9, 30.0, 2);
    Item* itemtres = new Item("Alcatra Grelhada", "Acompanha: arroz,feijão,farofa,fritas,alface,tomate e cenoura", 17.9, 30.0, 3);
    Item* itemquatro = new Item("Universitário sem carne", "arroz,feijão,farofa,fritas,alface,tomate e cenoura", 13.9, 30.0, 4);
    Item* itemcinco = new Item("Contrafilé Grelhado", "Acompanha: arroz,feijão,farofa,fritas,alface,tomate e cenoura", 21.9, 30.0, 5);
    Item* itemseis = new Item("Picanha Grelhada", "Acompanha: arroz,feijão,farofa,fritas,alface,tomate e cenoura", 26.9, 30.0, 6);
    Item* itemsete = new Item("Risoto de Camarão", "arroz, camarão, molho vermelho e mussarela", 26.9, 30.0, 7);
    Item* itemoito = new Item("Risoto Vegetariano", "arroz, palmito, champignon, molho branco e mussarela", 18.9, 30.0, 8);
    Item* itemnove = new Item("Risoto 4 Queijos", "arroz, molho branco, mussarela, parmesão, provolone e gorgonzola", 20.9, 30.0, 9);
    Item* itemdez = new Item("Filé de Tilapia", "Acompanha: arroz,purê ou fritas,alface e tomate", 19.9, 30.0, 10);
    Item* itemonze = new Item("Strogonoff Bovino", "Acompanha: arroz,batata palha, alface e tomate", 19.9, 30.0, 11);
    Item* itemdoze = new Item("Strogonoff de Frango", "Acompanha: arroz,batata palha, alface e tomate", 18.9, 30.0, 12);
    Item* itemtreze = new Item("Arroz á Piamontese", "Acompanha: alcatra ao molho madeira", 23.9, 30.0, 13);
    Item* itemcatorze = new Item("Picanha(200g)", "Acompanha: arroz, fritas, vinagrete, farofa, alface e tomate", 34.9, 30.0, 14);
    Item* itemquinze = new Item("Salmão ao molho de maracujá", "Acompanha: risoto de palmito e mix de folhas", 32.9, 30.0, 15);
    Item* itemdezesseis = new Item("Filé ao Cogumelo", "Medalhões de filé mignon com bacon grelhados, cobertos com creme de catupiry servido sobre o molho roti com champignon, acompanhado de arroz à grega.", 39.9, 30.0, 16);
    Item* itemdezessete = new Item("Parmegiana de Tilápia", "Acompanha: arroz, purê ou fritas, alface e tomate", 21.9, 30.0, 17);
    Item* itemdezoito = new Item("Parmegiana de Beringela", "Acompanha: arroz, purê ou fritas, alface e tomate", 26.9, 30.0, 18);
    Item* itemdezenove = new Item("Parmegiana de Boi", "Acompanha: arroz, purê ou fritas, alface e tomate" ,21.9, 30.0, 19);
    Item* itemvinte = new Item("Parmegiana de Frango", "Acompanha: arroz, purê ou fritas, alface e tomate", 26.9, 30.0, 20);
    Item* itemvinteum = new Item("Salada Especial", "Alface, tomate, cenoura, pepino, palmito e brócolis", 26.9, 30.0, 21);
    Item* itemvintedois = new Item("Espaguete à bolonhesa", "Molho especial de tomate, carne moída, mussarela e cheiro verde", 18.9, 30.0, 22);
    Item* itemvintetres = new Item("Espaguete na Chapa", "Frango desfiado, milho, bacon, calabresa, mussarela e cheiro verde", 18.9, 30.0, 23);
    Item* itemvintequatro = new Item("Lasanha 4 Queijos", "Molho branco, provolone, parmesão, mussarela e catupiry", 26.9, 30.0, 24);
    Item* itemvintecinco = new Item("Lasanha Bolonhesa", "Molho vermelho, carne moida, mussarela", 26.9, 30.0, 25);
    Item* itemvinteseis = new Item("Lasanha Frango com Catupiry", "Molho rosé, frango desfiado, mussarela e catupiry", 26.9, 30.0, 26);
    Item* itemvintesete = new Item("Porção Picanha bovina com fritas(600g)", 62.9, 30.0, 27);
    Item* itemvinteoito = new Item("Porção Contrafilé com fritas(600g)", 52.9, 30.0, 28);
    Item* itemvintenove = new Item("Porção Torresmo com linguiça(600g)", 39.9, 30.0, 29);
    Item* itemtrinta = new Item("Porção Fritas com queijo e bacon", 12.9, 30.0, 30);
    Item* itemtrintaum = new Item("Refrigerante Coca Cola 1L", 9.9, 0.0, 31);
    Item* itemtrintadois = new Item("Guaraná Kuat 600ml", 6.9, 0.0, 32);
    Item* itemtrintatres = new Item("Suco Natural de Laranja", 10.9, 10.0, 33);
    Item* itemtrintaquatro = new Item("Brownie", 6.9, 0.0, 34);
            

    itemum->ImprimeItem();          // testar 



    delete itemum; 
    delete itemdois;
    delete itemtres;
    delete itemquatro;
    delete itemcinco;
    delete itemseis;
    delete itemsete;
    delete itemoito;
    delete itemnove;
    delete itemdez;
    delete itemonze;
    delete itemdoze;
    delete itemtreze;
    delete itemcatorze;
    delete itemquinze;
    delete itemdezeseis;
    delete itemdezessete;
    delete itemdezoito;
    delete itemdezenove;
    delete itemvinte;
    delete itemvinteum;
    delete itemvintedois;
    delete itemvintetres;
    delete itemvintequatro;
    delete itemvintecinco;
    delete itemvinteseis;
    delete itemvintesete;
    delete itemvinteoito;
    delete itemvintenove;
    delete itemtrinta;
    delete itemtrintaum;
    delete itemtrintadois;
    delete itemtrintatres;
    delete itemtrintaquatro;

    

    return 0;
}

