    #include <stdio.h>

/* Buenas Profesor, en este codigo, mientras lo estaba haciendo le aagregue una parte que usted no habia explicado,
lo hice totalmente por mi cuenta ivestigando por que me hacia ilusion (me refiero usar el break y el continue ) lo hice para 
poder agregar funcion de salir mientras la opcion de jugar esta activada, si esta mal me deja saber y se lo envio sin esa parte*/

    int main()
    {
        int opcion = 0;
        int cantidadJugadas = 0;
        int numeros[100];
        float dinero[100];
        int i;
        int volveralmenu = 0 ;



            
                printf("--- Juego de Loteria hecho por Diego Fabian ---\n");

                printf("\nPara empezar ingresa la cantidad de jugadas que quieres:");
                scanf("%d", &cantidadJugadas);

                while (cantidadJugadas < 1 || cantidadJugadas > 100) 
                {

                    if(cantidadJugadas < 1) 
                    {
                        printf("\nLas cantidades no pueden ser negativas");
                    
                    }
                    
                    else

                    {
                        printf("\nLas cantidades no pueden ser mayor que 100");
                    
                    }    

                    printf("\nIngresa otra cantidad:");
                    scanf("%d", &cantidadJugadas);

                 

                    
                    }

                    if (cantidadJugadas > 1 ||cantidadJugadas < 100 )
                    {
                     printf("\n--- Cantidad almacenada correctamente --- \n");
                    }

                
            

        while(opcion != 2)
        {
            printf("\nMenu Principal\n");
            printf("\n\n1. Jugar\n");
            printf("2. Salir");
            printf("\n\nOpcion: ");
            scanf("%d", &opcion);

            if(opcion == 1)
            {
                if(cantidadJugadas <= 0)
                {
                    printf("Primero debe elegir la cantidad de jugadas.\n");

                }

                else
                {
                    for(i = 0; i < cantidadJugadas; i++)
                    {
                        if(volveralmenu == 1)
                        {
                            continue; 
                          
                        }

                        printf("\nJugada %d\n", i + 1);
                  

                        printf("Numero (1-40) o poner 0 para salir: ");
                        scanf("%d", &numeros[i]);

                        while(numeros[i] < 1 || numeros[i] > 40)

                        {

                    if(numeros[i] == 0)
                    {
                        volveralmenu = 1;

                        break; 

                    }
                    
                    else{
                    printf("Numero invalido. Digite otro: ");
                    
                            scanf("%d", &numeros[i]);  
                        }
                    }
                    
                    if (numeros[i] != 0){
                        printf("Cantidad de dinero: ");
                        scanf("%f", &dinero[i]);
                    
                    }
                    }
                    if (volveralmenu == 1 )
                    {  printf("\n\n---Proceso cancelado---\n\n");}
                    
                    
                    else {
                    printf("\n--- JUGADAS REGISTRADAS ---\n");

                    for(i = 0; i < cantidadJugadas; i++)
                    {
                        printf("Numero: %d  Dinero: %.2f  Premio: %.2f\n",
                            numeros[i],
                            dinero[i],
                            dinero[i] * 1000);
                        }
                        
                    }
                    
                    
                }
            }
            
            else if(opcion == 2)
            {
                printf("Saliendo...\n");
            }
            else
            {
                printf("Opcion invalida.\n");
            }
        }

        return 0;

    }