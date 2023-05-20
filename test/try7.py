import dash
from   dash import html, dcc, Input, Output, State
import random

app = dash.Dash(__name__)


app.layout = html.Div([
    html.Div([
        html.H3('Extend multiple traces at once'),
        dcc.Graph(
            id='graph',
            figure=dict(
                data=[{'x': [0],
                       'y': [0],
                       'mode':'lines+markers'
                       },
                      {'x': [0],
                       'y': [0],
                       'mode':'lines'
                       },
                      {'x': [0],
                       'y': [0],
                       'mode':'markers'
                       }],
            )
        ),
    ]),
    dcc.Interval(
        id='interval',
        interval = (3 * 1000),
        n_intervals = 0),
])


@app.callback(Output('graph',    'extendData'),
              Input ('interval', 'n_intervals'),
              State ('graph',    'figure')
             )
def update_traces(n_intervals, existing):
    x = [[existing['data'][0]['x'][-1] + 1],
         [existing['data'][1]['x'][-1] - .5, existing['data'][1]['x'][-1] + 1],
         [existing['data'][2]['x'][-1] + .1]
        ]
    y = [[random.random()],
         [0, random.random()],
         [random.random()]
        ]
    return (dict(x=x, y=y),
            [0, 1, 2]
           )


if __name__ == '__main__':
    app.run_server(debug=True)
    