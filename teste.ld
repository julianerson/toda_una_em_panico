SECTIONS
{
    /* Define o início do binário, ex: 0x08000000 ou 0x0 */
    . = 0x0; 

    /* Cria uma seção específica para o cabeçalho no início */
    .header : {
        BYTE(0xCA)
        BYTE(0xFE)
        BYTE(0xF0)
        BYTE(0xDA)      
    }

    /* Coloca o código/dados normais depois */
    .text : { *(.text) }
    .data : { *(.data) }
}
