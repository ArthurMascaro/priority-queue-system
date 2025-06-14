🏦 Fila de Atendimento em C  
Este projeto consiste na implementação de um sistema de fila de atendimento na linguagem C, com suporte a filas geral, prioritária e registro dos clientes atendidos.

🧠 Funcionalidades  
✅ Inicialização de filas (geral, prioridade e atendidos)  
✅ Enfileirar clientes nas filas geral e prioritária (`add_to_queue`)  
✅ Lógica de atendimento com até 3 clientes prioritários seguidos antes de atender fila geral (`serve_customer`)  
✅ Registro e impressão da lista de clientes já atendidos (`print_served`)  
✅ TAD de fila circular estática com operações básicas:  
   - `queue_init`  
   - `queue_enqueue`  
   - `queue_dequeue`  
   - `queue_empty`  

```bash
# Compilação
make

# Uso
./main_program

# Exemplo de uso:
# g João       → adiciona "João" à fila geral
# p Maria      → adiciona "Maria" à fila prioritária
# s            → atende próximo cliente (prioritário até 3 seguidos)
# f            → imprime todos os atendidos
