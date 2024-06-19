#EXERCÍCIO 1:

class Carros:
    def __init__(self, modelo, cor, ano):
        self.modelo = modelo
        self.cor = cor
        self.ano = ano

meu_carro = Carros(modelo='La Ferrari', cor='Veremlha', ano=2015)

#EXERCÍCIO 2:

#Definindo classes e aplicando o método construtor, o método especial __str__ e a função listar

class Restaurante:
    restaurante = []
    def __init__(self, nome, categoria):
        self._nome = nome.title()
        self._categoria = categoria
        self._ativo = False
        Restaurante.restaurante.append(self)
    def __str__(self):
        return f'{self._nome} | {self._categoria} | {self.ativo}'
    
    @classmethod
    def listar(cls):
        print(f'{'Nome do restaurante'.ljust(25)} | {'Categoria'.ljust(25)} | {'Status'}'.ljust(25))
        for restaurante in cls.restaurante:
            print(f'{restaurante._nome.ljust(25)} | {restaurante._categoria.ljust(25)} | {restaurante.ativo.ljust(25)}')
    
    #modifica uma propriedade
    @property 
    def ativo(self):
        return 'verdadeiro' if self._ativo else 'falso'

    def alternar_status(self):
        self._ativo = not self._ativo

restaurante_plaza = Restaurante('plaza', 'Gourmet')
restaurante_pizza = Restaurante('pizzaPlanet', 'Pizzaria')

#print do init(construtor)
print(vars(restaurante_plaza))
print(vars(restaurante_pizza))

#print do self (self é a convenção, mas pode ser qualquer nome)
print()
print(restaurante_plaza)
print(restaurante_pizza)

#função listar
print()
Restaurante.listar()
