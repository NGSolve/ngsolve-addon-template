def test_import():
    # you need to import ngsolve before importing the extension
    # such that all runtime dependencies are loaded
    import ngsolve
    import ngsolve_addon_template


def test_my_function():
    import ngsolve
    import ngsolve_addon_template

    assert ngsolve_addon_template.my_function() == 1.0
    assert ngsolve_addon_template.my_function(1.0) == 1.0
    assert ngsolve_addon_template.my_function(2.0) == 4.0
