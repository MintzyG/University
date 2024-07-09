ExUnit.start()

defmodule CriacaoStruct do
  @doc """
  Cria uma struct para representar um ponto no espaço 2D e uma função para mover o ponto.

  ## Dicas
  - Defina uma struct com campos para coordenadas x e y.
  - Crie uma função que recebe uma struct ponto e um par de valores para mover o ponto.

  ## Exemplos

      iex> ponto = CriacaoStruct.criar(2, 3)
      iex> CriacaoStruct.mover(ponto, 5, 7)
      %{x: 7, y: 10}
  """

  defmodule Pt do
    defstruct x: 0, y: 0
  end

  @spec criar(integer, integer) :: map
  @spec mover(map, integer, integer) :: map
  def criar(x, y) do
    ponto = %Pt{x: x, y: y}
    ponto
  end

  def mover(ponto, dx, dy) do
    p = %Pt{x: dx + ponto.x, y: dy + ponto.y}
    p
  end
end

defmodule CriacaoStructTest do
  use ExUnit.Case, async: true

  test "move o ponto corretamente" do
    ponto = CriacaoStruct.criar(2, 3)
    assert %{x: 7, y: 10} = CriacaoStruct.mover(ponto, 5, 7)
  end
end
