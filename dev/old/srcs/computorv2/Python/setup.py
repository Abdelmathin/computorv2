import os
from setuptools import setup, Extension

def main():
    app_directory = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))
    module = Extension(
        "computorv1",
        sources = [
            os.path.join(app_directory, "CPython/computorv1.c"),
            os.path.join(app_directory, "C/sources/computorv1_init.c"),
            os.path.join(app_directory, "C/sources/computorv1_next.c"),
            os.path.join(app_directory, "C/sources/computorv1_clear.c"),
            os.path.join(app_directory, "C/sources/computorv1_parse.c"),
            os.path.join(app_directory, "C/sources/computorv1_solve.c"),
            os.path.join(app_directory, "C/sources/computorv1_isnull.c"),
            os.path.join(app_directory, "C/sources/computorv1_release.c"),
            os.path.join(app_directory, "C/sources/computorv1_acquire.c"),
            os.path.join(app_directory, "C/sources/computorv1_isinteger.c"),
            os.path.join(app_directory, "C/sources/computorv1_isvariable.c"),
            os.path.join(app_directory, "C/sources/computorv1_parse_sign.c"),
            os.path.join(app_directory, "C/sources/computorv1_skip_spaces.c"),
            os.path.join(app_directory, "C/sources/computorv1_syntaxerror.c"),
            os.path.join(app_directory, "C/sources/computorv1_reduced_form.c"),
            os.path.join(app_directory, "C/sources/computorv1_print_number.c"),
            os.path.join(app_directory, "C/sources/computorv1_fraction_part.c"),
            os.path.join(app_directory, "C/sources/computorv1_parse_exponent.c"),
            os.path.join(app_directory, "C/sources/computorv1_parse_coefficient.c"),
            os.path.join(app_directory, "C/sources/computorv1_irreducible_fraction.c"),
            os.path.join(app_directory, "C/sources/computorv1_equation.c"),
            os.path.join(app_directory, "C/sources/computorv1_degree.c"),
            os.path.join(app_directory, "C/sources/computorv1_copy_number.c"),
            os.path.join(app_directory, "C/sources/computorv1_fini.c"),
        ]
    )

    setup(
        name        = "computorv1",
        version     = "v1.0.0",
        description = "a simple equation solving library",
        ext_modules = [module],
    )

if (__name__ == "__main__"):
    main()
