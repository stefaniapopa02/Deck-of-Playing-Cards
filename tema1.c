#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct carte{
    char nume;
    char culoare;
    int valoare;
    struct carte* next;} carte, *pcarte;

typedef struct culori{
    char culoare;
    struct culori* next;} culori, *pculori;

pculori initializare_culori(){

    pculori c_list = (pculori) malloc(sizeof(culori));
    c_list->culoare = 's';
    c_list->next = NULL;

    pculori iter = c_list;
    pculori new;

    new = (pculori) malloc(sizeof(culori));
    new->culoare = 'h';
    new->next = NULL;
    iter->next = new;
    iter = iter->next;

    new = (pculori) malloc(sizeof(culori));
    new->culoare = 'c';
    new->next = NULL;
    iter->next = new;
    iter = iter->next;

    new = (pculori) malloc(sizeof(culori));
    new->culoare = 'd';
    new->next = NULL;
    iter->next = new;
    iter = iter->next;

    iter->next = c_list;

    return c_list;
}


pcarte create(char nume, char culoare, int valoare) {
    pcarte head = (pcarte)malloc(sizeof(carte));  
    head->nume = nume;
    head->culoare = culoare;
    head->valoare = valoare;
    head->next = NULL;
    return head;
}

int isEmpty(pcarte head){
    return(head == NULL);

}

pcarte insert(pcarte head, char nume, char culoare, int valoare){
    if(isEmpty(head)){
        head = create(nume, culoare, valoare);
        return head;
    }
    
    pcarte iter = head;

    while(iter->next != NULL){
        iter = iter->next;
    }

    pcarte new = create(nume, culoare, valoare);
    iter->next = new;
    return head;
}

pcarte front_insert(pcarte head, char nume, char culoare, int valoare){
    if(isEmpty(head)){
        head = create(nume, culoare, valoare);
        return head;
    }

    pcarte new = create(nume, culoare, valoare);
    new->next = head;
    head = new;
    return head;
}

pcarte Top(pcarte head){
    if(isEmpty(head))
        return NULL;

    pcarte prev = head;
    pcarte cur = head->next;

    if(cur == NULL){
        return prev;
    }

    while(cur->next != NULL){
        prev = prev->next;
        cur = cur->next;
    }

    prev->next = NULL;
    return cur;
}

pcarte initializare_pachet(pcarte head){
    head=insert(head, 'A', 's', 15);
    head=insert(head, 'A', 'h', 15);
    head=insert(head, 'A', 'c', 15);
    head=insert(head, 'A', 'd', 15);
    head=insert(head, 'K', 's', 14);
    head=insert(head, 'K', 'h', 14);
    head=insert(head, 'K', 'c', 14);
    head=insert(head, 'K', 'd', 14);
    head=insert(head, 'Q', 's', 13);
    head=insert(head, 'Q', 'h', 13);
    head=insert(head, 'Q', 'c', 13);
    head=insert(head, 'Q', 'd', 13);
    head=insert(head, 'J', 's', 12);
    head=insert(head, 'J', 'h', 12);
    head=insert(head, 'J', 'c', 12);
    head=insert(head, 'J', 'd', 12);
    head=insert(head, 'T', 's', 10);
    head=insert(head, 'T', 'h', 10);
    head=insert(head, 'T', 'c', 10);
    head=insert(head, 'T', 'd', 10);
    head=insert(head, '9', 's', 9);
    head=insert(head, '9', 'h', 9);
    head=insert(head, '9', 'c', 9);
    head=insert(head, '9', 'd', 9);
    head=insert(head, '8', 's', 8);
    head=insert(head, '8', 'h', 8);
    head=insert(head, '8', 'c', 8);
    head=insert(head, '8', 'd', 8);
    head=insert(head, '7', 's', 7);
    head=insert(head, '7', 'h', 7);
    head=insert(head, '7', 'c', 7);
    head=insert(head, '7', 'd', 7);
    head=insert(head, '6', 's', 6);
    head=insert(head, '6', 'h', 6);
    head=insert(head, '6', 'c', 6);
    head=insert(head, '6', 'd', 6);
    head=insert(head, '5', 's', 5);
    head=insert(head, '5', 'h', 5);
    head=insert(head, '5', 'c', 5);
    head=insert(head, '5', 'd', 5);
    head=insert(head, '4', 's', 4);
    head=insert(head, '4', 'h', 4);
    head=insert(head, '4', 'c', 4);
    head=insert(head, '4', 'd', 4);
    head=insert(head, '3', 's', 3);
    head=insert(head, '3', 'h', 3);
    head=insert(head, '3', 'c', 3);
    head=insert(head, '3', 'd', 3);
    head=insert(head, '2', 's', 2);
    head=insert(head, '2', 'h', 2);
    head=insert(head, '2', 'c', 2);
    head=insert(head, '2', 'd', 2);

    return head;
}

pcarte inversare(pcarte head, pcarte new_head){

    int i;
    pcarte top;

    for(i = 1; i <= 52; i++){
        top = Top(head);
        new_head = insert(new_head, top->nume, top->culoare, top->valoare);
        free(top);
    }
    
    return new_head;

}

pcarte npiles(pcarte head, int nr, int ordine[52]){

    pcarte new[52], iter = head , temp;
    int n = 52 / nr;

    for(int i = 0; i < 52; i++){
        new[i]  = NULL;
    }
    
    for(int i = 0; i < nr; i++){
        for(int j = 1; j <= n; j++){
            new[i] = insert(new[i], iter->nume, iter->culoare, iter->valoare);
            temp = iter;
            iter = iter->next;
            free(temp);
        }
    }
    head = NULL;
    for(int i = 0; i < nr; i++){
        iter = new[ordine[i] - 1];
        for(int j = 1; j <= n; j++){
            head = insert(head, iter->nume, iter->culoare, iter->valoare);
            iter = iter->next;
        }
    }
    return head;
}

pcarte intercalare(pcarte head, pcarte new1, pcarte new2){
    int i;
    pcarte iter = head;
    pcarte temp;

    for(i = 1; i <= 26; i++){
        new1 = insert(new1, iter->nume, iter->culoare, iter->valoare);
        temp = iter;
        iter = iter->next;
        free(temp);
    }
    while(iter != NULL){
        new2 = insert(new2, iter->nume, iter->culoare, iter->valoare);
        temp = iter;
        iter = iter->next;
        free(temp);
    }
    head = NULL;
    pcarte iter1 = new1;
    pcarte iter2 = new2;

    for(i = 1; i <= 26; i++){

        head = insert(head, iter1->nume, iter1->culoare, iter1->valoare);
        head = insert(head, iter2->nume, iter2->culoare, iter2->valoare);

        iter1 = iter1->next;
        iter2 = iter2->next;
        
    }
    return head;
}

pcarte mongean(pcarte head, pcarte new_head){

    int i;
    pcarte iter = head;
    pcarte temp;

    for(i = 1; i <= 52; i++){
        if(i % 2 == 1){
            new_head = insert(new_head, iter->nume, iter->culoare, iter->valoare);
        }
        else{
            new_head = front_insert(new_head, iter->nume, iter->culoare, iter->valoare);
        }
        temp = iter;
        iter = iter->next;
        free(temp);
    }
    return new_head;

}

pcarte rs_carte_noua(pcarte *jucator, pculori c_list, int carti_ramase){
    
    pcarte prev, iter;

    if((*jucator)->culoare == c_list->culoare){
        iter = (*jucator);
        (*jucator) =(*jucator)->next;
        return iter;
    }

    if(carti_ramase > 1){
        prev = (*jucator), iter =(*jucator)->next;

        while (iter != NULL) {
            if(iter->culoare == c_list->culoare){
                prev->next = iter->next;
                return iter;
            }
            prev = prev->next;
            iter = iter->next;
        } 
    }

    return NULL;
}

int rs_terminat(pcarte jucator[4]){
   if(jucator[0] != NULL && jucator[1] != NULL && jucator[2] != NULL && jucator[3] != NULL){
        return 0;
    }
    if(jucator[0] == NULL){
        return 1;
    }
    if(jucator[1] == NULL){
        return 2;
    }
    if(jucator[2] == NULL){
        return 3;
    }
    if(jucator[3] == NULL){
        return 4;
    }
}

int rollingstone(pcarte pachet){

    pcarte jucator[4], iter = pachet;
    pcarte temp;
    int i, j;

    for(i = 0; i < 4; i++){
        jucator[i] = NULL;
    }
    for(i = 0; i < 4; i++){
        for(j = 1; j <= 13; j++){
            jucator[i] = insert(jucator[i], iter->nume, iter->culoare, iter->valoare);
            temp = iter;
            iter = iter->next;
            free(temp);
        }
    }


    pculori culori = initializare_culori();

    int carti_ramase[4] = {13, 13, 13, 13};
    int jucator_curent = 0;
    pcarte carte_jucata, joc = NULL;
    int k = jucator_curent;


    while(rs_terminat(jucator) == 0){
        for(i = 1; i <= 4; i++){
            carte_jucata = rs_carte_noua(&jucator[k], culori, carti_ramase[k]);
            if(carte_jucata == NULL){
                culori = culori->next;
            }
            else{
                carti_ramase[k]--;
                break;
            }
        }
    
        if(rs_terminat(jucator)){
            return rs_terminat(jucator);
        }

        joc = insert(joc, carte_jucata->nume, carte_jucata->culoare, carte_jucata->valoare);
        free(carte_jucata);

        if(k == 3){
            k = 0;
        }
        else{
            k++;
        }
               
        for(i=1; ; i++){
            carte_jucata = rs_carte_noua(&jucator[k], culori, carti_ramase[k]);
            if(carte_jucata != NULL){
                carti_ramase[k]--;

                if(rs_terminat(jucator)){
                    return rs_terminat(jucator);
                }

                joc = insert(joc, carte_jucata->nume, carte_jucata->culoare, carte_jucata->valoare);
                free(carte_jucata);

                if(k == 3){
                    k = 0;
                }
                else{
                    k++;
                }

            }
            else{
                break;
            }
    
             
        }

        while(joc != NULL){
            jucator[k] = insert(jucator[k], joc->nume, joc->culoare, joc->valoare);
            carti_ramase[k]++;
            temp = joc;
            joc = joc->next;
            free(temp);
        }
        culori = culori->next;
         
    }

}


int main()
{
    pcarte head = NULL;
    pcarte pachet = initializare_pachet(head);

    FILE *fin = fopen("./in", "r");
    FILE *fout = fopen("./out", "w");

    char task[1000];
    fscanf(fin, "%s", task);
    printf("%s\n", task);
    if(strcmp(task, "amestecare") == 0){
        char type[60];
        int times;
        fscanf(fin, "%d",&times);

        for(int i = 1; i <= times; i++){
            fscanf(fin, "%s", type);
            if(strcmp(type, "inversare") == 0){
                pachet = inversare(pachet, NULL);
            }
            if(strcmp(type, "mongean") == 0){
                pachet = mongean(pachet, NULL);
            }
            if(strcmp(type, "intercalare") == 0){
                pachet = intercalare(pachet, NULL, NULL);
            }
            if(strcmp(type, "npiles") == 0){
                int nr, ordine[52];
                fscanf(fin, " %d", &nr);
                for(int j = 0; j < nr; j++){
                    fscanf(fin, " %d", &ordine[j]);
                }
                pachet = npiles(pachet, nr, ordine);
            }
        }

        pcarte iter = pachet;

        while(iter != NULL){
            fprintf(fout, "%c%c ", iter->nume, iter->culoare);
            iter = iter->next;
        }
        
    }

    if(strcmp(task, "rollingstone") == 0){
        char type[60];
        int times;
        fscanf(fin, "%d",&times);

        for(int i = 1; i <= times; i++){
            fscanf(fin, "%s", type);
            if(strcmp(type, "inversare") == 0){
                pachet = inversare(pachet, NULL);
            }
            if(strcmp(type, "mongean") == 0){
                pachet = mongean(pachet, NULL);
            }
            if(strcmp(type, "intercalare") == 0){
                pachet = intercalare(pachet, NULL, NULL);
            }
            if(strcmp(type, "npiles") == 0){
                int nr, ordine[52];
                fscanf(fin, " %d", &nr);
                for(int j = 0; j < nr; j++){
                    fscanf(fin, " %d", &ordine[j]);
                }
                pachet = npiles(pachet, nr, ordine);
            }
        }
        fprintf(fout, "%d", rollingstone(pachet));
        
    }
    
   fclose(fin);
   fclose(fout);

}

