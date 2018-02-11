/*
 * Archivo: BandaTransportadora.c
 * Descripcion: Cola de pilas.
 * Autores: Albert Diaz 11-10278, Fabio Suarez
 * Ultima fecha de modificacion: *19/10/2017*
 */

colaa* crecreate_queue(){ //initializes the queue

    colaa* cola = malloc(sizeof(colaa));

    cola->size = 0;
    cola->head = NULL;
    cola->tail = NULL;
    cola->ccEnBanda = 0;

    return cola;
}

void enenqueue(colaa* q, Producto pro){

    Node* temp = (Node*)malloc(sizeof(Node)); //allocates

    if (temp == NULL) 
    {
        printf("Unable to allocate memory\n");
    }

    else if ((q->size) == 0) 
    {
        temp->next = q->head;
        temp->product = pro;
        q->head = temp;
        q->head->next = NULL;
        q->tail = temp;
        q->tail->next = NULL;
        q->size = (q->size) + 1; //bumps the counter for how many elements are in the queue
        q->ccEnBanda = q->ccEnBanda + pro.size;
    }

    else
    {
        temp->next = q->tail;
        q->tail->prev = temp;
        temp->product = pro;
        q->tail = temp;
        q->size = (q->size) + 1; //bumps the counter for how many elements are in the queue
        q->ccEnBanda = q->ccEnBanda + pro.size;
    }
}

Producto* dedequeue(colaa* q){

    int salida = 0;

    if((q->size) == 0) 
    {
        printf("La cola esta vacia \n");

        return NULL;
    }

    else
    {
        Node* temp;
        Node* temp2;

        temp = q->head;
        q->head = q->head->prev;
        temp2 = temp;
        //printf("%p\n", &(temp2->product));
        //printf("----%s\n", casa.name);
        free(temp);
        q->size = (q->size) - 1; //subtracts from counter
        q->ccEnBanda = q->ccEnBanda - temp2->product.size;

        return &(temp2->product);
    }
}

int tope(colaa* q){

    if ((q->size) == 0) 
    {
        printf("La cola esta vacia \n");
    }

    Node* temp = q->head;

    Producto value = temp->product;
    printf("%d\n",value.size );

    return value.size;
}