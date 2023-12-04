#include "primary_compability_solver.h"

using namespace::paull_unger;

paull_unger::primary_compability_solver::primary_compability_solver(ms::table g_table)
{
    _g_table = g_table;
}

comp_table paull_unger::primary_compability_solver::solve()
{
    comp_table comp_table(_g_table.get_width());

    for (unsigned long long state_a = 0; state_a < _g_table.get_width() - 1; ++state_a)
    {
        for (unsigned long long state_b = state_a + 1; state_b < _g_table.get_width(); ++state_b)
        {
            for (unsigned long long input = 0; input < _g_table.get_height(); ++input)
            {
                pair states_pair(_g_table.get_value(input, state_a), _g_table.get_value(input, state_b));

                if (states_pair.is_compatible_by_outs() == false)
                {
                    comp_table.set_value(false, state_a, state_b);

                    break;
                }
            }
        }
    }

    return comp_table;
}
