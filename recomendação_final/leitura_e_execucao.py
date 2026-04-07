import pandas as pd
import csv
import time
import meu_modulo

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

def Verificar_produtos(lista_compra):
    print("Digite o código do cliente (ou -1 para sair): ")
    codigo = input()
    while(codigo!="-1"):
        if codigo not in lista_compra.indiceclientes:
            print("cliente não encontrado")
            codigo = input("Digite o código do cliente (ou -1 para sair): ")
            continue
    
        idx_cliente = lista_compra.indiceclientes[codigo]

        print(f"produtos comprados por {codigo}")
        
        for idx_produto in lista_compra.compras[idx_cliente]:
            nome_produto = lista_compra.produtos[idx_produto]
            print(nome_produto)

        codigo = input("Digite o código do cliente (ou -1 para sair): ")

def visualizar_produtos(lista_compra, Matriz_similaridade, matriz_compra, num_Produtos):
    k = 3
    for i in range(k):
        codigo = input("\nDigite o código do cliente para recomendação: ")
        
        if codigo not in lista_compra.indiceclientes:
            print("Cliente não encontrado.")
            continue

        idx_cliente = lista_compra.indiceclientes[codigo]

        vizinhos = meu_modulo.vetor_vizinhos(
            Matriz_similaridade, 
            lista_compra.clientes, 
            idx_cliente
        )

        ranking = meu_modulo.vetor_ranking(
            Matriz_similaridade,
            vizinhos,
            matriz_compra,
            lista_compra.indiceclientes,
            idx_cliente,
            num_Produtos
        )
        
     
        ranking_ordenado = meu_modulo.ordenar_vetor_rankeamento(ranking)

        print(f"Recomendações para {codigo}:")
        count = 0
        t = 0
        while t < len(ranking_ordenado) and count < k:
            item = ranking_ordenado[t]
            if item.score > 0:
                nome_produto = lista_compra.produtos[item.index]
                print(f"- {nome_produto} (score: {item.score:.2f})")
                count += 1 
            t += 1

def main():
    lista_compra = ListaCompra()
    leitura(lista_compra)

    Verificar_produtos(lista_compra)

    num_clientes = len(lista_compra.clientes)
    num_Produtos = len(lista_compra.produtos)

    matriz_compra_binaria = meu_modulo.gerar_matriz_compras(
        lista_compra.compras,
        num_clientes,
        num_Produtos
    )

    escolha = int(input("1- Otimizada\n2- Normal\nEscolha: "))
    usar_otimizado = True if escolha == 1 else False

    inicio = time.perf_counter()
    Matriz_similaridade = meu_modulo.gerar_matriz_similaridade(
        matriz_compra_binaria,
        num_clientes,
        num_Produtos,
        usar_otimizado
    )
    final = time.perf_counter()
    print(f"Tempo de cálculo da similaridade: {final - inicio:.4f} segundos")

    visualizar_produtos(lista_compra, Matriz_similaridade, matriz_compra_binaria, num_Produtos)

if __name__ == "__main__":
    main()