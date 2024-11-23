#ifndef STACK_H
#define STACK_H

template <typename T>
struct Node {
    T data;
    Node* next;
};

/**
 * @file stack.h
 * @brief Declaração da classe template Stack para implementação de uma pilha.
 * 
 * @tparam T Tipo de dados armazenados na pilha.
 */

/**
 * @class Stack
 * @brief Classe template que implementa uma pilha.
 * 
 * @tparam T Tipo de dados armazenados na pilha.
 */
template <typename T>
class Stack {
    private:
        Node<T>* top; /**< Ponteiro para o nó do topo da pilha. */
        
    public:
        /**
         * @brief Construtor padrão da classe Stack.
         */
        Stack();

        /**
         * @brief Destrutor da classe Stack.
         */
        ~Stack();

        /**
         * @brief Adiciona um elemento ao topo da pilha.
         * 
         * @param data O dado a ser adicionado à pilha.
         */
        template <typename T>
        void push(T data);

        /**
         * @brief Remove e retorna o elemento do topo da pilha.
         * 
         * @return O dado removido do topo da pilha.
         */
        template <typename T>
        T pop();

        /**
         * @brief Retorna o elemento do topo da pilha sem removê-lo.
         * 
         * @return O dado do topo da pilha.
         */
        template <typename T>
        T peek() const;

        /**
         * @brief Verifica se a pilha está vazia.
         * 
         * @return true se a pilha estiver vazia, false caso contrário.
         */
        template <typename T>
        bool isEmpty() const;
};

#endif