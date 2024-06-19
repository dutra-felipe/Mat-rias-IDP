from modelos.avaliacao import Avaliacao

class Restaurante:
    restaurante = []
    def __init__(self, nome, categoria):
        self._nome = nome.title()
        self._categoria = categoria
        self._ativo = False
        self._avaliacao = []
        Restaurante.restaurante.append(self)
    
    def __str__(self):
        return f'{self._nome} | {self._categoria} | {self.ativo}'
    
    @classmethod
    def listar(cls):
        print()
        print(f'{'Nome do restaurante'.ljust(25)} | {'Categoria'.ljust(25)} | {'Avaliação'.ljust(25)} | {'Status'}'.ljust(25))
        print()
        for restaurante in cls.restaurante:
            print(f'{restaurante._nome.ljust(25)} | {restaurante._categoria.ljust(25)} | {str(restaurante.media_avaliacoes).ljust(25)} | {restaurante.ativo.ljust(25)}')
    
    @property 
    def ativo(self):
        return 'Ativo' if self._ativo else 'Inativo'

    def alternar_status(self):
        self._ativo = not self._ativo

    def recebe_avaliacao(self, cliente, nota):
        avaliacao = Avaliacao(cliente, nota)
        self._avaliacao.append(avaliacao)
    
    
    @property
    def media_avaliacoes(self):
        if not self._avaliacao:
            return 'Sem avaliação!'
        soma_das_notas = sum(avaliacao._nota for avaliacao in self._avaliacao)/2
        quantidade_de_notas = len(self._avaliacao)
        media = round(soma_das_notas / quantidade_de_notas, 1)
        return media
