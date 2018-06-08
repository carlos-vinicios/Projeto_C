#ifndef CATEGORIA_H
#define CATEGORIA_H

int storeCategoria(Categoria categoria); //salvar as informações de um novo recebimento de Categoria

int updateCategoria(Categoria categoria); //alteração de informações de um recebimento de Categoria

int deleteCategoria(int id); //exclui o Categoria recebido

Categoria categoriaById(int id); //carrega as informações (dados do usuario) para exibição ou edição

Categorias *listAllCategorias(); //lista todos os Categorias

Categorias *filterCategoriaByMonth(Categorias *listCategorias, char *date); //lista os recebimentos de Categoria com base em uma data

Categorias *filterCategoriaBetweenDate(Categorias *listCategorias, char *initDate, char *endDate); //lista os Categorias com base em dois meses dados

Categorias *filterCategoriaBetweenValue(Categorias *listCategorias, float init_value, float end_value); //lista os recebimentos de Categoria com base em um valor

#endif // CATEGORIA_H
