[Mesh]
  [mesh]
    type = FileMeshGenerator
    file = rectangle_mesh.e
  []
[]

[Variables]
  [u]
    family = LAGRANGE
    order = FIRST
    initial_condition = 0.0
  []
[]

[Functions]
  [exact_solution]
    type = ParsedFunction
    expression = "sin(pi*x)*sin(pi*y)"
  []
  [source_function]
    type = ParsedFunction
    expression = "2.0*pi*pi*sin(pi*x)*sin(pi*y)"
  []
[]

[Kernels]
  [diffusion]
    type = Diffusion
    variable = u
  []
  [source]
    type = BodyForce
    variable = u
    function = source_function
  []
[]

[BCs]
  [dirichlet_all]
    type = DirichletBC
    variable = u
    # Using the boundary names you defined in Cubit
    boundary = 'left right top bottom'
    value = 0.0
  []
[]
[Postprocessors]
  [l2_error]
    type = ElementL2Error
    variable = u
    function = exact_solution
  []
  [num_dofs]
    type = NumDOFs
  []
[]

[Executioner]
  type = Steady
  solve_type = 'NEWTON'
  petsc_options_iname = '-ksp_type -ksp_rtol'
  petsc_options_value = 'gmres     1e-8'
[]

[Outputs]
  exodus = true
  csv = true
  console = true
[]