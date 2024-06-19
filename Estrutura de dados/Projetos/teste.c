void criarNovaTarefa() {
  // Cria uma nova tarefa
  Tarefa tarefa;
  tarefa.id = lista.size + 1;
  tarefa.status = A_FAZER;
  printf("Digite o título da tarefa: ");
  scanf(" %[^\n]s ", tarefa.titulo);

  // Adiciona a tarefa à lista
  NoTarefa *novoNo = (NoTarefa *)malloc(sizeof(NoTarefa));
  novoNo->tarefa = tarefa;
  novoNo->proximo = NULL;
  novoNo->anterior = NULL;

  if (lista.primeiro == NULL) {
    lista.primeiro = novoNo;
    lista.ultimo = novoNo;
  } else {
    lista.ultimo->proximo = novoNo;
    novoNo->anterior = lista.ultimo;
    lista.ultimo = novoNo;
  }

  lista.size++;
}

void editarTarefa(unsigned int id) {
  // Procura a tarefa na lista
  NoTarefa *no = lista.primeiro;
  while (no != NULL && no->tarefa.id != id) {
    no = no->proximo;
  }

  // Se a tarefa não foi encontrada, retorna
  if (no == NULL) {
    printf("Tarefa não encontrada.\n");
    return;
  }

  // Edita a tarefa
  printf("Digite o novo título da tarefa: ");
  scanf(" %[^\n]s ", no->tarefa.titulo);
}

void deletarTarefa(unsigned int id) {
  // Procura a tarefa na lista
  NoTarefa *no = lista.primeiro;
  while (no != NULL && no->tarefa.id != id) {
    no = no->proximo;
  }

  // Se a tarefa não foi encontrada, retorna
  if (no == NULL) {
    printf("Tarefa não encontrada.\n");
    return;
  }

  // Remove a tarefa da lista
  if (no == lista.primeiro) {
    lista.primeiro = no->proximo;
  } else {
    no->anterior->proximo = no->proximo;
  }

