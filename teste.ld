//licença GNU
/*    toda_una_em_panico | a calculadora para engenheiros novatos desesperados
*    Copyright (C) 2026  
*   Contact: nilson.m.b.abreu@gmail.com
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <https://www.gnu.org/licenses/>*/


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
