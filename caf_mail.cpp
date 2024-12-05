#include <caf/exec_main.hpp>
#include <caf/event_based_actor.hpp>

int caf_main(caf::actor_system& sys)
{
    auto a1 = sys.spawn([](caf::event_based_actor* self)
    {
        return caf::behavior{
            [self](std::size_t value) -> std::size_t
            {
                return value << 1u;
            },
            [self](caf::get_atom)
            {
                self->mail(std::size_t{2}).request(self, caf::infinite).then([self](std::size_t res)
                {
                    self->println("Result: {}", res);
                });
            }
        };
    });

    return 0;
}

CAF_MAIN()
