[Mesh]
  [mesh]
    type = FileMeshGenerator
    file = star_domain.e
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
    expression = "exp(x+y)"
  []
  [rhs_function]
    type = ParsedFunction
    expression = "-2.0*exp(x+y)"
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
    function = rhs_function
  []
[]

[BCs]
  [dirichlet_star]
    type = FunctionDirichletBC
    variable = u
    # Using the exact sideset name from your Cubit journal
    boundary = 'star_boundary'
    function = exact_solution
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
  # Untangled the PETSc options arrays
  petsc_options_iname = '-ksp_type -ksp_rtol'
  petsc_options_value = 'gmres     1e-8'
[]

[Outputs]
  exodus = true
  csv = true
  console = true
[]