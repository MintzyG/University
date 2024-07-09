ExUnit.start()

defmodule ContagemElementos do
  @spec run(lista) :: integer
  def run(lista) do
    count(lista)
  end

  def count([_head | tail]) do
    cond do
      length(tail) > 1 -> 1 + count(tail)
      length(tail) == 1 -> 1
    end
  end

  def count([]) do
    0
  end
end

defmodule ContagemElementosTest do
  use ExUnit.Case, async: true

  test "conta os elementos de uma lista vazia" do
    assert ContagemElementos.run([]) == 0
  end

  test "conta os elementos de uma lista com vários itens" do
    assert ContagemElementos.run([1, 2, 3, 4, 5]) == 5
  end
end
