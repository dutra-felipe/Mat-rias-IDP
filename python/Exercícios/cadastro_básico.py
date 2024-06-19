import os

restaurantes = []

def finaliza_app():
    os.system('cls')
    print("Fim do app")

def voltar_menu():
    input('Aperte enter para voltar ao menu principal')
    main()

def opcao_invalida():
    os.system('cls')
    print('Opção Inválida!\n')
    voltar_menu()

def exibir_subtitulo(texto):
    os.system('cls')
    linha = '*' * (len(texto))
    print(linha)
    print(texto)
    print(linha)
    print()

def cadastra_restaurante():
    exibir_subtitulo('Cadastro de novos restaurantes')
    nome_do_restaurante = input('Digite o nome do restaurante que deseja cadastrar: ')
    categoria = input(f'\nDigite o nome da categoria do restaurante {nome_do_restaurante}: ')
    dados_do_restaurante = {'nome':nome_do_restaurante, 'categoria':categoria, 'ativo':False}
    restaurantes.append(dados_do_restaurante)
    os.system('cls')
    print(f'O restaurante {nome_do_restaurante} foi cadastrado com sucesso!\n')
    voltar_menu()

def lista_restaurantes():
    exibir_subtitulo('Listando os restaurantes') 

    print(f'{'Nome do restaurante'.ljust(22)} | {'Categoria'.ljust(20)} | Status\n')
    for restaurante in restaurantes:
        nome_restaurante = restaurante['nome']
        categoria = restaurante['categoria']
        ativo = 'Ativado' if restaurante['ativo'] else 'Desativado'
        print(f'- {nome_restaurante.ljust(20)} | {categoria.ljust(20)} | {ativo}\n')

    voltar_menu()

def status_restaurante():
    exibir_subtitulo('ALterando estado do restaurante')
    nome_restaurante = input('Digite o nome do restaurante que deseja alterar o estado: ')
    restaurante_encontrado = False
    
    for restaurante in restaurantes:
        if nome_restaurante == restaurante['nome']:
            restaurante_encontrado = True
            restaurante['ativo'] = not restaurante['ativo']
            mensagem = f'O restaurante {nome_restaurante} foi ativado com sucesso' if restaurante['ativo'] else f'O restaurante {nome_restaurante} foi desativado com sucesso'
            print(mensagem)
    
    if not restaurante_encontrado:
        print('O restaurante não foi encontrado.')
        
    voltar_menu()

def exibe_menu():
    print("\nMenu de Opções\n")
    print("1. Cadastrar restaurante")
    print("2. Listar restaurantes")
    print("3. Alternar status do restaurante")
    print("4. Sair\n")
    
def escolher_opcoes():
    try:
        opcao_escolhida = int(input('Escolha uma opção: '))
        
        if opcao_escolhida == 1: 
            cadastra_restaurante()
        elif opcao_escolhida == 2: 
            lista_restaurantes()
        elif opcao_escolhida == 3: 
            status_restaurante() 
        elif opcao_escolhida == 4: 
            finaliza_app()
        else:
            opcao_invalida()
    except: 
        opcao_invalida()

def main():
    os.system('cls')
    exibe_menu()
    escolher_opcoes()

if __name__ == '__main__':
    main()