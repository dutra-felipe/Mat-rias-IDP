from modelos.restaurantes import Restaurante

restaurante_praca = Restaurante('braga palace', 'Gourmet')
restaurante_mexicano = Restaurante('chicorito', 'Mexicana')
restaurante_japones = Restaurante('japapei', 'Japonesa')
restaurante_praca.recebe_avaliacao('Roger', 10)
restaurante_praca.recebe_avaliacao('Graco', 8)

restaurante_mexicano.alternar_status()

def main():
    Restaurante.listar()

if __name__ == '__main__':
    main()
