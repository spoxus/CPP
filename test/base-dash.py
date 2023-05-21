from   dash import html, dcc, Input, Output, State, Dash
import random

app = Dash(__name__)

data = [{'x': [0],
         'y': [0],
         'name': 'bid',
         'mode': 'lines+markers'
        },
        {'x': [0],
         'y': [0],
         'name': 'ask',
         'mode': 'lines'
        },
        {'x': [0],
         'y': [0],
         'name': 'SMA1',
         'mode': 'markers'
        }
]

figure = dict(data = data)

app.layout = html.Div([
    html.Div([
        html.H3('Extend multiple traces at once'),
        dcc.Graph(
            id     = 'graph',
            figure = figure
        )
    ]),
    dcc.Interval(
        id          = 'interval',
        interval    = (5 * 1000),
        n_intervals = 0
    )
])


@app.callback(
    Output('graph',    'extendData'),
    Input ('interval', 'n_intervals'),
    State ('graph',    'figure')
)

def update_traces(n_intervals, existing):
    # I want to find out what x and y do
    # x: move right, 1, 2, 3, 4, 5...
    # y: the value associated with x
    x = [[existing['data'][0]['x'][-1] + 1],
         [existing['data'][1]['x'][-1] - .5,
          existing['data'][1]['x'][-1] + 1
         ],
         [existing['data'][2]['x'][-1] + .1]
        ]
    y = [[random.random() * 3], # this is trace 'bid'
         [0, random.random()],
         [random.random()]
        ]
    # 
    return (dict(x=x, y=y),
            # what does this list do???
            # if i change anything here, won't work
            [0,
             1,
             2,
             #3
            ]
           )


if __name__ == '__main__':
    app.run_server(debug=True)
    