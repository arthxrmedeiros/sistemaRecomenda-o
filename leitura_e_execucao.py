import pandas as pd
import csv

class ListaCompra:
    def __init__(self):
        self.clientes = []
        self.indiceclientes = {}
        self.produtos = []
        self.indiceprodutos = {}
        self.compras = []

def leitura(lista_compra):

    with open('dados_venda_cluster_0.csv','r') as f:
        for linha in csv.reader(f):
                    cliente_nome = linha[1]
                    produto_nome = linha[3] 

                    if cliente_nome not in lista_compra.indiceclientes:

                        novo_idx = len(lista_compra.clientes)
                        
                        lista_compra.clientes.append(cliente_nome)

                        lista_compra.indiceclientes[cliente_nome] = novo_idx
                        lista_compra.compras.append([])

                    if produto_nome not in lista_compra.indiceprodutos:
                        novo_idx_prod = len(lista_compra.produtos)
                        lista_compra.produtos.append(produto_nome)
                        lista_compra.indiceprodutos[produto_nome] = novo_idx_prod

                    idx_c = lista_compra.indiceclientes[cliente_nome]
                    idx_p = lista_compra.indiceprodutos[produto_nome]

                    lista_compra.compras[idx_c].append(idx_p)

def main():
    lista_compra = ListaCompra()
    leitura(lista_compra)