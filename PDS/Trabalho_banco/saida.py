import pandas as pd
import os

# cria arquivo csv
def criar_arquivo_csv(nome_arquivo, dados):
    with open(nome_arquivo, 'w') as arquivo:
        arquivo.write("Colaborador;Valor_a_pagar\n")
        for colaborador, valor in dados.items():
            arquivo.write(f"{colaborador};{valor}\n")

def criar_arquivo_csv_bancos(nome_banco, dados):
    with open(f"{nome_banco}.csv", 'w') as arquivo:
        arquivo.write("Colaborador;Valor_a_depositar\n")
        for colaborador, salario in dados.items():
            arquivo.write(f"{colaborador};{salario}\n")

# leitura de dados
dados_csv = pd.read_csv('dados_tratados.csv', delimiter=';')

bancos = {}
irpf = {}
inss = {}
sindicato = {}

# leitura dados_tratados.csv
for index, linha in dados_csv.iterrows():
    colaborador = linha['colaborador']
    salario_com_beneficios = linha['salario_com_beneficios']
    irpf_calculado = linha['irpf_calculado']
    inss_calculado = linha['inss_calculado']
    sindicato_calculado = linha['sindicato_calculado']
    tipo_banco = linha['banco']

    if tipo_banco not in bancos:
        bancos[tipo_banco] = {} 
    
    bancos[tipo_banco][colaborador] = salario_com_beneficios
    irpf[colaborador] = irpf_calculado
    inss[colaborador] = inss_calculado
    sindicato[colaborador] = sindicato_calculado

#exclui banco.csv se o arquivo existir, mas não existir o banco em dados_tratados.csv
for filename in os.listdir('.'):
    if filename.endswith('.csv') and filename[:-4] not in bancos:
        os.remove(filename)

for tipo_banco, dados in bancos.items():
    criar_arquivo_csv_bancos(tipo_banco, dados)
    
criar_arquivo_csv('IRPF.csv', irpf)
criar_arquivo_csv('INSS.csv', inss)
criar_arquivo_csv('Sindicato.csv', sindicato)